//STARTSETUP
static char help[] =
  "Resolve um sistema linear tridiagonal de tamanho definido pelo usu�rio.\n";

#include <petsc.h>

int main(int argc,char **args) {
  PetscErrorCode ierr;
  Vec    x, b, xexact;
  Mat    A;
  KSP    ksp;
  int    m = 4, i, Istart, Iend, j[3];
  double v[3], xval, errnorm;

  PetscInitialize(&argc,&args,NULL,help);

  ierr = PetscOptionsBegin(PETSC_COMM_WORLD,"tri_","Op��es para tri",""); 
	 CHKERRQ(ierr);
  ierr = PetscOptionsInt("-m","Dimens�o do sistema","tri.c",m,&m,NULL); 
	 CHKERRQ(ierr);
  ierr = PetscOptionsEnd(); CHKERRQ(ierr);

  ierr = VecCreate(PETSC_COMM_WORLD,&x); CHKERRQ(ierr);
  ierr = VecSetSizes(x,PETSC_DECIDE,m); CHKERRQ(ierr);
  ierr = VecSetFromOptions(x); CHKERRQ(ierr);
  ierr = VecDuplicate(x,&b); CHKERRQ(ierr);
  ierr = VecDuplicate(x,&xexact); CHKERRQ(ierr);

  ierr = MatCreate(PETSC_COMM_WORLD,&A); CHKERRQ(ierr);
  ierr = MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,m,m); CHKERRQ(ierr);
  ierr = MatSetOptionsPrefix(A,"a_"); CHKERRQ(ierr);
  ierr = MatSetFromOptions(A); CHKERRQ(ierr);
  ierr = MatSetUp(A); CHKERRQ(ierr);
//ENDSETUP
  ierr = MatGetOwnershipRange(A,&Istart,&Iend); CHKERRQ(ierr);
  for (i=Istart; i<Iend; i++) {
    if (i == 0) {
      v[0] = 3.0;  v[1] = -1.0;
      j[0] = 0;    j[1] = 1;
      ierr = MatSetValues(A,1,&i,2,j,v,INSERT_VALUES); CHKERRQ(ierr);
    } else {
      v[0] = -1.0;  v[1] = 3.0;  v[2] = -1.0;
      j[0] = i-1;   j[1] = i;    j[2] = i+1;
      if (i == m-1) {
        ierr = MatSetValues(A,1,&i,2,j,v,INSERT_VALUES); CHKERRQ(ierr);
      } else {
        ierr = MatSetValues(A,1,&i,3,j,v,INSERT_VALUES); CHKERRQ(ierr);
      }
    }
    xval = exp(cos(i));
    ierr = VecSetValues(xexact,1,&i,&xval,INSERT_VALUES); CHKERRQ(ierr);
  }
  ierr = MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY); CHKERRQ(ierr);
  ierr = MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY); CHKERRQ(ierr);
  ierr = VecAssemblyBegin(xexact); CHKERRQ(ierr);
  ierr = VecAssemblyEnd(xexact); CHKERRQ(ierr);
  ierr = MatMult(A,xexact,b); CHKERRQ(ierr);

  ierr = KSPCreate(PETSC_COMM_WORLD,&ksp); CHKERRQ(ierr);
  ierr = KSPSetOperators(ksp,A,A); CHKERRQ(ierr);
  ierr = KSPSetFromOptions(ksp); CHKERRQ(ierr);
  ierr = KSPSolve(ksp,b,x); CHKERRQ(ierr);

  ierr = VecAXPY(x,-1.0,xexact); CHKERRQ(ierr);
  ierr = VecNorm(x,NORM_2,&errnorm); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,
         "Erro para sistema de ordem m = %d � |x-xexact|_2 = %.1e\n",m,errnorm); 
	 CHKERRQ(ierr);

  KSPDestroy(&ksp);  MatDestroy(&A);
  VecDestroy(&x);  VecDestroy(&b);  VecDestroy(&xexact);
  PetscFinalize();
  return 0;
}
//ENDSOLVE

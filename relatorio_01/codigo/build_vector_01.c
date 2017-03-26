static char help[] = "Cria um vetor com tamanho definido pelo usuário \n\n";

#include <petscvec.h>

int main(int argc, char **argv){
	Vec x;
	int n = 20;
	PetscScalar one = 1.0, dot;

	PetscInitialize(&argc, &argv, 0,0);
	PetscOptionsGetInt(NULL,NULL,"-n",&n,PETSC_NULL);
	VecCreate(PETSC_COMM_WORLD,&x);
	VecSetSizes(x,PETSC_DECIDE,n);
	VecSetFromOptions(x);
	VecSet(x,one);
	VecDot(x,x,&dot);
	PetscPrintf(PETSC_COMM_WORLD,"Vector length %d \n", (int)dot);
	VecDestroy(&x);
	PetscFinalize();
return 0;
}

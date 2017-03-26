#include <petsc.h>

int main(int argc, char **argv) {
  PetscErrorCode ierr;
  int            rank, i;
  double         localval, globalsum;

  PetscInitialize(&argc,&argv,NULL,"Calcula 'e' em paralelo com PETSc.\n\n");

  ierr = MPI_Comm_rank(PETSC_COMM_WORLD,&rank); CHKERRQ(ierr);

  // calcula  1 / n!  onde n = (rank do processo) + 1
  localval = 1.0;
  for (i = 2; i < rank+1; i++)
      localval /= i;

  // soma as contribuições de cada processo
  ierr = MPI_Allreduce(&localval, &globalsum, 1, MPI_DOUBLE, MPI_SUM,
                       PETSC_COMM_WORLD); CHKERRQ(ierr);

  // imprime a estimativa de e
  ierr = PetscPrintf(PETSC_COMM_WORLD,
      "O valor da constante 'e' é aproximadamente: %17.15f\n",globalsum); CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_SELF,
      "rank %d did %d flops\n",rank,(rank > 0) ? rank-1 : 0); CHKERRQ(ierr);

  PetscFinalize();

  return 0;
}

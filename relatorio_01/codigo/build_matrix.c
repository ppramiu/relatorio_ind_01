static char help[] = "Monta uma matriz 4x4 usando Mat.\n";

#include <petsc.h>

int main(int argc, char **args) {
	Mat	A;
	int 	i, j[4] = {0, 1, 2, 3};
	double	aA[4][4] ={{1.0, 2.0, 3.0, 0.0},
			{ 2.0, 1.0, -2.0, -3.0},	
			{-1.0, 1.0, 1.0, 0.0},
			{ 0.0, 1.0, 1.0, -1.0}};

	PetscInitialize(&argc, &args, NULL, help);

	MatCreate(PETSC_COMM_WORLD, &A);
	MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,4,4);
	MatSetFromOptions(A);
	MatSetUp(A);
	for (i=0; i<4; i++) {
		MatSetValues(A,1,&i,4,j,aA[i],INSERT_VALUES);
	}
	MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY);
	MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY);

	MatDestroy(&A);

	PetscFinalize();
	return 0;
}

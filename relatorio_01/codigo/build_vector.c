static char help[] = "Monta um vetor 10 x 1 usando Vec.\n";

#include <petsc.h>

int main(int argc, char **args) {
	Vec	x;
	int    i[10] = {0, 1, 2, 3,4, 5, 6, 7, 8, 9};
	double v[10] = {11.0, 7.0, 5.0, 3.0, 6.0,
		       11.0, 7.0, 5.0, 3.0, 6.0};
			
	PetscInitialize(&argc, &args, NULL, help);
	
	VecCreate(PETSC_COMM_WORLD,&x);
	VecSetSizes(x,PETSC_DECIDE,10);
	VecSetFromOptions(x);
	VecSetValues(x,10,i,v,INSERT_VALUES);
	VecAssemblyBegin(x);
	VecAssemblyEnd(x);

	VecDestroy(&x);

	PetscFinalize();
	return 0;
}

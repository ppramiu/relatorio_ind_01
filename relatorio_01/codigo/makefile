include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules

code_euler: code_euler.o  chkopts
	-${CLINKER} -o code_euler code_euler.o  ${PETSC_LIB}
	${RM} code_euler.o

build_vector_01: build_vector_01.o  chkopts
	-${CLINKER} -o build_vector_01 build_vector_01.o  ${PETSC_LIB}
	${RM} build_vector_01.o


build_vector: build_vector.o  chkopts
	-${CLINKER} -o build_vector build_vector.o  ${PETSC_LIB}
	${RM} build_vector.o

build_matrix: build_matrix.o  chkopts
	-${CLINKER} -o build_matrix build_matrix.o  ${PETSC_LIB}
	${RM} build_matrix.o

solve_linear_ksp: solve_linear_ksp.o  chkopts
	-${CLINKER} -o solve_linear_ksp solve_linear_ksp.o  ${PETSC_LIB}
	${RM} solve_linear_ksp.o

solve_linear_arbitrary: solve_linear_arbitrary.o  chkopts
	-${CLINKER} -o solve_linear_arbitrary solve_linear_arbitrary.o  ${PETSC_LIB}
	${RM} solve_linear_arbitrary.o

poisson_fd_2d: poisson_fd_2d.o  chkopts
	-${CLINKER} -o poisson_fd_2d poisson_fd_2d.o  ${PETSC_LIB}
	${RM} poisson_fd_2d.o

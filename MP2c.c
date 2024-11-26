#include <stdio.h>
#include <stdlib.h>
// for calling the C kernel
#include "MP2ckernel.c"

extern float asmsdot(int n, float* vectorA, float* vectorB, float* sdot);

int main () {
	/* declare variables:
		int n for size of vectors
		float vectorA[] for VectorA
		float vectorB[] for VectorB
		float pointer sdot for storing sdot of VectorA and VectorB
	*/
	int n = 4;
	float vectorA[] = {1.0, 2.0, 3.10, 4.25};
	float vectorB[] = {5.0, 6.0, 70.20, 8.5};
	double *ctime = (double *)malloc(sizeof(double));
	double *asmtime = (double *)malloc(sizeof(double));
	float *sdot = (float *)malloc(sizeof(float)); 
	*sdot = 0.0;
	*ctime = 0.0;
	*asmtime = 0.0;
	
	calcsdot(n, vectorA, vectorB, sdot, ctime);
	printf("C Kernel\n----------------\n");
	printf("Dot product from C: %f\n", *sdot);
	printf("Execution time: %f nanoseconds\n\n", *ctime);
	
	*sdot = 0.0;
		
	asmsdot(n, vectorA, vectorB, sdot);
	printf("ASM Kernel\n----------------\n");
	printf("Dot product from ASM: %f\n\n", *sdot);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

// for calling the C kernel
#include "MP2Ckernel.c"

extern float asmsdot(int n, float* vectorA, float* vectorB, float* sdot);

int main () {
	/* declare variables:
		int n for size of vectors
		float vectorA[] for VectorA
		float vectorB[] for VectorB
		float pointer sdot for storing sdot of VectorA and VectorB
	*/
	int i, n=4;
	float vectorA[] = {10.0, 20.0, 3.0, 40.0};
	float vectorB[] = {50.0, 6.0, 7.0, 8.0};
	float *sdot = (float *)malloc(sizeof(float));
	
	calcsdot(n, vectorA, vectorB, sdot);
	printf("C Kernel\n----------------\n");
	printf("Dot product from C: %f\n\n", *sdot);
	
	asmsdot(n, vectorA, vectorB, sdot);
	printf("ASM Kernel\n----------------\n");
	printf("Dot product from ASM: %f\n\n", *sdot);
	
	return 0;
}

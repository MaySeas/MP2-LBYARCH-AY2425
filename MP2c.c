#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
	int n = 1048576; // for 2^20 size arrays
//	int n = 166777216; // for 2^24 size arrays
//	int n = 1073741824; // for 2^30 size arrays
	float vectorA[] = {};
	float vectorB[] = {};
	
	double *ctime = (double *)malloc(sizeof(double));
	double *asmtime = (double *)malloc(sizeof(double));
	
	float *sdot = (float *)malloc(sizeof(float)); 
	*sdot = 0.0;
	*ctime = 0.0;
	*asmtime = 0.0;
	
	int i;
	// timer variables
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapse, elapse1;
	QueryPerformanceCounter(&li);
	PCFreq = (double)(li.QuadPart);
	
	// initialize arrays with the number of elements in n
	for (i = 0; i < n; i++) {
		vectorA[i] = 3.0;
		vectorB[i] = 2.0;
	}
	
	for (i = 0; i < 20; i++) {
		QueryPerformanceCounter(&li);
		start - li.QuadPart;
		calcsdot(n, vectorA, vectorB, sdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapse = ((double)(end-start))* 1000.0 / PCFreq;
		elapse1 = elapse1 + elapse;
	}
	
	printf("C Kernel\n----------------\n");
	printf("Dot product from C: %f\n", *sdot);
	printf("Average execution time for 20 runs: %f ms\n\n", elapse1/20);
	
	*sdot = 0.0;
		
	asmsdot(n, vectorA, vectorB, sdot);
	printf("ASM Kernel\n----------------\n");
	printf("Dot product from ASM: %f\n\n", *sdot);
	
	return 0;
}

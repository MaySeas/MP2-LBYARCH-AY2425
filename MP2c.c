#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// for calling the C kernel
#include "MP2ckernel.c"

extern void asmsdot(int n, float* vectorA, float* vectorB, float* sdot);

int main () {
	/* declare variables:
		int n for size of vectors
		float vectorA[] for VectorA
		float vectorB[] for VectorB
		float pointer sdot for storing sdot of VectorA and VectorB
	*/
//	long long N = 4;
	long long N = 166777216; //for 2^24
//	long long N = 1073741824; //for 2^30
//	long long N = 1048576; // for 2^20 size arrays
	float *vectorA;
	vectorA = (float*)malloc(N*sizeof(*vectorA)); //vectorA
	float *vectorB;
	vectorB = (float*)malloc(N*sizeof(*vectorA)); //vectorB

	// error checking for memory allocation of vectors
	if (vectorA == NULL) {
		printf("Initialization for Vector A went wrong.\n");
		exit(1);
	}
	
	if (vectorB == NULL) {
		printf("Initialization for Vector B went wrong.\n");
		exit(1);
	}
	
	// the dot product
	float *sdot = (float *)malloc(sizeof(float)); 
	*sdot = 0.0;
	
	int i, j; // counters
	// timer variables
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapse, elapse1;
	QueryPerformanceCounter(&li);
	PCFreq = (double)(li.QuadPart);
	
	// initialize arrays with the number of elements in n
	printf("Initializing arrays...\n");
	for (i = 0; i < N; i++) {
		vectorA[i] = 2.0;
		vectorB[i] = 2.0;
	}
	
	for (j = 0; j < 20; j++) {
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		calcsdot(N, vectorA, vectorB, sdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapse = ((double)(end-start)) * 1000.0 / PCFreq;
		elapse1 = elapse1 + elapse; // get sum of all elapses for averaging later
	}
	
	printf("C Kernel\n----------------\n");
	printf("Dot product from C: %f\n", *sdot);
	printf("Average execution time for 20 runs: %f ms\n\n", elapse1/20); // get average
	
	*sdot = 0.0; //ensures that sdot results aren't from C kernel
	elapse1 = 0;
	
	for (j = 0; j < 20; j++) {
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		asmsdot(N, vectorA, vectorB, sdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapse = ((double)(end-start)) * 1000.0 / PCFreq;
		elapse1 = elapse1 + elapse; // get sum of all elapses for averaging later
	}
	
	printf("ASM Kernel\n----------------\n");
	printf("Dot product from ASM: %f\n", *sdot);
	printf("Average execution time for 20 runs: %f ms\n\n", elapse1/20); // get average
	
	return 0;
}

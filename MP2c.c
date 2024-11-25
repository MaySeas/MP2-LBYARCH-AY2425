#include <stdio.h>
#include <stdlib.h>

// for calling the C kernel
#include "MP2Ckernel.c"

// TODO: Use extern to include the asm kernel

int main () {
	/* declare variables:
		int n for size of vectors
		float vectorA[] for VectorA
		float vectorB[] for VectorB
		float pointer sdot for storing sdot of VectorA and VectorB
	*/
	int n;
	float vectorA[] = {1.0, 2.0, 3.0, 4.0};
	float vectorB[] = {5.0, 6.0, 7.0, 8.0};
	float* sdot;
	
	
	// TODO: Call C kernel and print result
	calcsdot(n, vectorA, vectorB, sdot);
	printf("&f", sdot);
	
	// TODO: Call the assembly kernel and print result
	printf("Placeholder for calling assembly code\n");
	printf("ASM Kernel Results\n")
	
	return 0;
}

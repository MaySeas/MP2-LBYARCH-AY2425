#include<stdio.h>
#include<stdlib.h>

void calcsdot(int n, float* vectorA, float* vectorB, float* sdot) {
	int j;
	for (j = 0; j < n; j++) {
		*sdot += vectorA[j] * vectorB[j];
	}
}

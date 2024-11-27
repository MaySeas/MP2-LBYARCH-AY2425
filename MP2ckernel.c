#include<stdio.h>
#include<stdlib.h>

float calcsdot(int n, float* vectorA, float* vectorB, float* sdot) {
	int j; //counter real
	for (j = 0; j < n; j++) {
		*sdot += vectorA[j] * vectorB[j];
	}
	return *sdot;
}

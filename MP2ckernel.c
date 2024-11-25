#include<stdio.h>
#include<stdlib.h>

//#include<MP2c.c>

//include the parameters for the two vectors also
float calcsdot(int n, float* vectorA, float* vectorB, float* sdot) {
	int j; //counter
	for (j = 0; j < n; j++) {
		*sdot += (vectorA[j] * vectorB[j]);
	}
	//TODO: include how to time this
	return *sdot;
}

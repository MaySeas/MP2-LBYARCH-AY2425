#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//include the parameters for the two vectors also
float calcsdot(int n, float* vectorA, float* vectorB, float* sdot, double* time) {
	struct timespec start, end;
    long nanoseconds;
    double elapsed;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	
	int j; //counter
	for (j = 0; j < n; j++) {
		*sdot += vectorA[j] * vectorB[j];
	}
	
	clock_gettime(CLOCK_MONOTONIC, &end);

	nanoseconds = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
    elapsed = nanoseconds / 1000000.0;
    
    *time = elapsed;
	
	return *sdot;
}

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

float dp(long N, float *pA, float *pB) {
    float R = 0.0;
	int j;
	for (j=0;j<N;j++) 
		R += pA[j]*pB[j]; 
	return R;
}

int main(int argc, char *argv[]) {
	struct timespec start, end;
	float* pA;
	float* pB;
	long N;
	int R;
	char* p;
    
    if(argc < 3){
    	printf("Error: R and N values not given. File should run in format ./dp1 1000 10 \n");
    	return 0;
    } else {
        N = (long)strtol(argv[1], &p, 10);
        R = (int)strtol(argv[2], &p, 10);
        pA = (float*)malloc(N * sizeof(float));
        pB = (float*)malloc(N * sizeof(float));
        for (int i = 0; i < N; ++i) { 
            *(pA + i) = 1.0;
            *(pB + i) = 1.0;
        }
	} 

	clock_gettime(CLOCK_MONOTONIC, &start); 			
	for (int i = 0; i < R; ++i)
		dp(N, pA, pB);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	double time_usec=(((double)end.tv_sec *1000000 + (double)end.tv_nsec/1000) - ((double)start.tv_sec * 1000000 + (double)start.tv_nsec/1000));
	printf("N: %ld T: %.03lf B: %.03f F: %.03f \n", N, time_usec, (2 * N * sizeof(float)/time_usec/10e9) ,(2*N*(R/2))/time_usec);
}
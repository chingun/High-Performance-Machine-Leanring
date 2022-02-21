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
	int R;
	char* p;
	long N;
    double time;
    double bandwidth;
    double flops;
    
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
			
	for (int i = 0; i < R/2; ++i)
		dp(N, pA, pB);

	clock_gettime(CLOCK_MONOTONIC, &start); 			
	for (int i = 0; i < R/2; ++i)
		dp(N, pA, pB);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	time = (((double)end.tv_sec * 1000000 + (double)end.tv_nsec / 1000) - ((double)start.tv_sec * 1000000 + (double)start.tv_nsec / 1000));
    time = (time / (R / 2.0));
    flops = (3 * N * R / 2.0) / (time * 1000000.0);
    bandwidth = (8 * N) / (time * 1000000.0);

	printf("N: %ld T: %.03lf sec B: %.03f GB/sec F: %.03f GFLOP/sec\n", N, time, bandwidth, flops);
}
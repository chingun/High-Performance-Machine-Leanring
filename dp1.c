#include <stdio.h>
#include <time.h>


float dp(long N, float *pA, float *pB) {
    float R = 0.0;
    int j;
    for (j = 0; j < N; j++)
        R += pA[j] * pB[j];
    return R;
}


int main(int argc, char *argv[]) {
    // retrieve the sizes of the vectors to calculate
    int vector_size = 1000;
    int compute_amount = 10;
    
    if (argc != 2){
        printf("The input is invalid");
        return;
    } else {
        vector_size = argv[1];
        compute_amount = argv[2];
        printf("Vectors to compute by is: \narg%d=%s", 1, vector_size);
        printf("Amount of times to recompute: \narg%d=%s", 2, compute_amount);
    }
    
    float* first = (float*) malloc(vector_size * sizeof(float));
    float* second = (float*) malloc(vector_size * sizeof(float));
    
    // Set all the variables in the vector
    for (int i = 0; i < vector_size; i++) {
        *(first + i) = 1.0;
        *(second + i) = 1.0;
    }
    
    for (int i = 0; i < compute_amount; i++){
        dp(vector_size, first, second);
    }
    
    return 0;
}

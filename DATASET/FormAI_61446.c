//FormAI DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <math.h>

#define N 10

int main() {
    
    float input[N] = {1, 0.3, 0.5, 0.8, 0.2, -0.1, 0.4, -0.6, 0.9, -0.2};
    float output[N] = {0};
    float b[3] = {0.5, 0.3, 0.2};
    float a[2] = {0.2, 0.1};
    
    for(int n = 2; n < N; n++) {
        output[n] = b[0] * input[n] + b[1] * input[n-1] + b[2] * input[n-2] - a[0] * output[n-1] - a[1] * output[n-2];
    }
    
    printf("Input: \n");
    for(int i = 0; i < N; i++) {
        printf("%f\n", input[i]);
    }
    
    printf("Output: \n");
    for(int i = 0; i < N; i++) {
        printf("%f\n", output[i]);
    }
    
    return 0;
}
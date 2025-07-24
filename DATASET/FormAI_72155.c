//FormAI DATASET v1.0 Category: Digital signal processing ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define BLOCK_SIZE 32

int main()
{
    int input_samples[BLOCK_SIZE], output_samples[BLOCK_SIZE];
    float coefficients[BLOCK_SIZE], sum;
    int i, j;
    
    //initialize input_samples and coefficients
    for(i = 0; i < BLOCK_SIZE; i++){
        input_samples[i] = i+1;
        coefficients[i] = sin(i * M_PI / BLOCK_SIZE);
    }
    
    //perform convolution
    for(i = 0; i < BLOCK_SIZE; i++){
        sum = 0;
        for(j = 0; j <= i; j++){
            sum += input_samples[j] * coefficients[i-j];
        }
        output_samples[i] = (int)sum;
    }
    
    //print output
    printf("Output samples:\n");
    for(i = 0; i < BLOCK_SIZE; i++){
        printf("%d ", output_samples[i]);
    }
    
    return 0;
}
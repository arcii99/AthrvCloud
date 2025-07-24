//FormAI DATASET v1.0 Category: Digital signal processing ; Style: invasive
#include<stdio.h> 
#include<stdlib.h> 
 
#define ARRAY_LENGTH 1000 
#define FILTER_LENGTH 8 

float input_signal[ARRAY_LENGTH];
float filter_kernel[FILTER_LENGTH];
float output_signal[ARRAY_LENGTH + FILTER_LENGTH - 1]; 

//initialize the input signal and filter kernel
void init_arrays() {
    for(int i=0; i<ARRAY_LENGTH; i++) {
        input_signal[i] = (float)(rand()%100)/100.0; //generate input signal values between 0 and 1
    }
    
    for(int i=0; i<FILTER_LENGTH; i++) {
        filter_kernel[i] = ((i+1)%2 == 0) ? -0.25 : 0.25; //alternate positive and negative values in filter kernel
    }
}

//perform convolution operation
void convolution() {
    float sum;
    int k, n;
    for(int i=0; i<ARRAY_LENGTH+FILTER_LENGTH-1; i++) {
        sum = 0.0;
        k = (i >= FILTER_LENGTH-1) ? i-FILTER_LENGTH+1 : 0;
        n = (i < ARRAY_LENGTH-1) ? i : ARRAY_LENGTH-1;
        for(int j=k; j<=n; j++) {
            sum += input_signal[j] * filter_kernel[i-j]; //multiply input signal with filter kernel
        }
        output_signal[i] = sum;
    }
}

int main () { 
    init_arrays(); //initialize input signal and filter kernel
    convolution(); //perform convolution operation
    
    //print output signal values
    printf("Output Signal:\n");
    for(int i=0; i<ARRAY_LENGTH+FILTER_LENGTH-1; i++) {
        printf("%.2f ", output_signal[i]);
    }
    printf("\n");
    
    return 0; 
}
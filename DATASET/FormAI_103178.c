//FormAI DATASET v1.0 Category: Digital signal processing ; Style: thoughtful
#include <stdio.h>

#define FILTER_ORDER 3
#define LENGTH_INPUT_SIGNAL 100

void fir_filter(int* input_signal, int* output_signal, int length_input_signal, int* filter_coefficients, int filter_order);

int main(){
    int input_signal[LENGTH_INPUT_SIGNAL];
    int output_signal[LENGTH_INPUT_SIGNAL];
    int filter_coefficients[FILTER_ORDER] = {2, -1, 1};
    int i;

    for(i=0; i<LENGTH_INPUT_SIGNAL; i++){
        input_signal[i] = i%10;
    }

    fir_filter(input_signal, output_signal, LENGTH_INPUT_SIGNAL, filter_coefficients, FILTER_ORDER);

    printf("Output signal:\n");
    for(i=0; i<LENGTH_INPUT_SIGNAL; i++){
        printf("%d ", output_signal[i]);
    }

    return 0;
}

void fir_filter(int* input_signal, int* output_signal, int length_input_signal, int* filter_coefficients, int filter_order){
    int i, j;
    int temp_output = 0;

    for(i=0; i<length_input_signal; i++){
        for(j=0; j<filter_order; j++){
            if(i-j >= 0){
                temp_output += input_signal[i-j] * filter_coefficients[j];
            }
        }
        output_signal[i] = temp_output;
        temp_output = 0;
    }
}
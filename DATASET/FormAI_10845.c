//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include<stdio.h>

int main(){
    printf("Hello! Let's do some digital signal processing!\n");
    printf("Today we will be looking at an example of low pass filtering.\n");
    float input_signal[10] = {1.0, 4.0, 7.0, 5.0, 3.0, 2.0, 1.0, 0.0, -3.0, -5.0};
    float output_signal[10];

    printf("Here is the input signal: ");
    for(int i=0; i<10; i++){
        printf("%.2f ", input_signal[i]);
    }

    // Implementing the low pass filter
    printf("\nFiltering the signal...\n");
    float alpha = 0.5;
    output_signal[0] = input_signal[0];
    for(int i=1; i<10; i++){
        output_signal[i] = alpha * input_signal[i] + (1-alpha) * output_signal[i-1];
    }

    printf("Here is the output signal: ");
    for(int i=0; i<10; i++){
        printf("%.2f ", output_signal[i]);
    }

    printf("\nDone! Isn't that beautiful?\n");
    return 0;
}
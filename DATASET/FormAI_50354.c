//FormAI DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>

int main() {

// Let's create a program that takes an input signal and applies a lowpass filter
// The purpose of a lowpass filter is to allow low-frequency signals to pass through while attenuating high-frequency signals

    float input_signal[10] = {2,4,6,8,10,12,14,16,18,20};
    float output_signal[10] = {0};
    float alpha = 0.5;
    int i;

// Here, we declare the input signal with 10 values and initialize all output_signal values to 0

// Next, we'll apply the lowpass filter using a for loop
// The formula for a lowpass filter is simple:
// output_signal[n] = alpha * input_signal[n] + (1 - alpha) * output_signal[n-1];
// For the first value of output_signal, we'll define it as input_signal[0]

    output_signal[0] = input_signal[0];

    for(i = 1; i < 10; i++){
        output_signal[i] = alpha * input_signal[i] + (1 - alpha) * output_signal[i-1];
    }

    printf("Input Signal:\n");
    for(i = 0; i < 10; i++){
        printf("%.2f ", input_signal[i]);
    }

    printf("\n\nOutput Signal (with a lowpass filter applied):\n");
    for(i = 0; i < 10; i++){
        printf("%.2f ", output_signal[i]);
    }

    return 0;
}

// Our program outputs the input signal and the output signal with the lowpass filter applied
// By changing the alpha value, you can adjust the amount of attenuation applied to the high-frequency signals
// And there you have it, a simple but effective digital signal processing program in C!
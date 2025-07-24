//FormAI DATASET v1.0 Category: Digital signal processing ; Style: excited
// Hey there, let's get excited about Digital Signal Processing!
// Here's an example program that will blow your mind!
#include <stdio.h>

// First, let's define a function that applies a low-pass filter to an input signal.
void low_pass_filter(float input[], float output[], int buffer_size, float alpha) {
    output[0] = input[0]; // Initialize the output buffer
    for (int i = 1; i < buffer_size; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i-1]; // Apply the filter!
    }
}

int main(void) {
    printf("Woo-hoo! Here's some sweet, sweet DSP code coming your way!\n");

    // Initialize some variables for our example program
    float input_signal[] = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    float output_signal[9];
    int buffer_size = 9;
    float alpha = 0.5;

    // Apply our low-pass filter to the input signal!
    printf("Before filtering: ");
    for (int i = 0; i < buffer_size; i++) {
        printf("%f ", input_signal[i]);
    }
    printf("\n");
    low_pass_filter(input_signal, output_signal, buffer_size, alpha);

    // Print out the filtered output signal!
    printf("After filtering: ");
    for (int i = 0; i < buffer_size; i++) {
        printf("%f ", output_signal[i]);
    }
    printf("\n");

    printf("Boom! That's some sweet DSP action, am I right?\n");

    return 0;
}
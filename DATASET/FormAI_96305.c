//FormAI DATASET v1.0 Category: Digital signal processing ; Style: retro
#include<stdio.h>

// Custom function to calculate the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Simple Digital signal processing function that echoes the input signal
void echo(int signal[], int len, int delay) {
    int output[len + delay]; // Create the output signal array with added delay
    
    for (int i = 0; i < len + delay; i++) {
        if (i < delay) { // If index is less than delay, set the output to 0
            output[i] = 0;
        } else {
            output[i] = max(signal[i] + signal[i - delay], -32768); // Add delayed signal to current signal and ensure no overflow
        }
    }
    
    // Print input and output signals
    printf("\nInput signal: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", signal[i]);
    }
    
    printf("\nOutput signal: ");
    for (int i = 0; i < len + delay; i++) {
        printf("%d ", output[i]);
    }
}

int main() {
    // Example input signal
    int input_signal[] = {1000, -2000, 3000, -4000, 5000};
    int signal_length = sizeof(input_signal) / sizeof(input_signal[0]); // Calculate length of input signal array
    
    // Call DSP function to echo input signal with a delay of 2
    echo(input_signal, signal_length, 2);
    
    return 0;
}
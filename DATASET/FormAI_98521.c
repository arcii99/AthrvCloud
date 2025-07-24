//FormAI DATASET v1.0 Category: Digital signal processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

// Basic FIR filter implementation 
float filter(float input, float coefficients[], int len, float state[]) {
    float output = 0;
    
    // Multiply coefficients with state and sum up
    for (int i = 0; i < len; i++) {
        output += coefficients[i] * state[i];
    }

    // Shift state by one and add input to the end
    for (int i = len - 1; i >= 1; i--) {
        state[i] = state[i - 1];
    }
    state[0] = input;

    return output;
}

// Generate input signal
void generate_signal(float signal[], int len) {
    float phase = 0;
    float freq = 20;
    float delta_freq = (PI * 2) / len;
    
    for (int i = 0; i < len; i++) {
        signal[i] = sin(phase);
        phase += freq * delta_freq;
    }
}

int main() {
    int N = 100; // Length of input signal
    float signal[N]; // Input signal
    float coefficients[] = {0.1, 0.2, 0.4, 0.2, 0.1}; // Filter coefficients
    int M = 5; // Length of filter

    float state[M]; // Filter state
    for (int i = 0; i < M; i++) state[i] = 0;

    generate_signal(signal, N); // Generate signal

    // Filter signal and output
    for (int i = 0; i < N; i++) {
        float filtered_signal = filter(signal[i], coefficients, M, state);
        printf("%f\n", filtered_signal);
    }

    return 0;
}
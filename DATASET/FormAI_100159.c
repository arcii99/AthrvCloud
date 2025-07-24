//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LENGTH 1000000

float input_signal[SIGNAL_LENGTH];
float output_signal[SIGNAL_LENGTH];

void apply_low_pass_filter(float signal[], float cutoff_frequency, float sampling_rate, int length) {
    float RC = 1.0 / (2 * M_PI * cutoff_frequency);
    float dt = 1.0 / sampling_rate;
    float alpha = dt / (RC + dt);
    float prev_output = signal[0];

    for(int i = 0; i < length; i++) {
        output_signal[i] = alpha * signal[i] + (1 - alpha) * prev_output;
        prev_output = output_signal[i];
    }
}

int main() {
    float sampling_rate = 100000; // Hz
    float cutoff_frequency = 5000; // Hz

    // Create input signal (random values between -1 and 1)
    for(int i = 0; i < SIGNAL_LENGTH; i++) {
        input_signal[i] = ((float)rand()/(float)(RAND_MAX)) * 2 - 1;
    }

    // Apply low pass filter to input signal
    apply_low_pass_filter(input_signal, cutoff_frequency, sampling_rate, SIGNAL_LENGTH);

    printf("Input signal:\n");
    for(int i = 0; i < 10; i++) {
        printf("%f\n", input_signal[i]);
    }

    printf("\nOutput signal:\n");
    for(int i = 0; i < 10; i++) {
        printf("%f\n", output_signal[i]);
    }

    return 0;
}
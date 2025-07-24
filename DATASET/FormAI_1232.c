//FormAI DATASET v1.0 Category: Audio processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

// Function to generate white noise
void generate_noise(float *buffer, int n) {
    for (int i = 0; i < n; i++) {
        buffer[i] = ((float)rand() / RAND_MAX) * 2 - 1;
    }
}

// Function to apply a low-pass filter to a signal
void lowpass_filter(float *buffer, int n, float cutoff_freq) {
    float RC = 1.0 / (2.0 * M_PI * cutoff_freq);
    float dt = 1.0 / SAMPLE_RATE;
    float alpha = dt / (RC + dt);
    float prev = buffer[0];
    for (int i = 1; i < n; i++) {
        float current = buffer[i];
        buffer[i] = alpha * current + (1 - alpha) * prev;
        prev = buffer[i];
    }
}

int main() {
    // Generate input signal
    float signal[BUFFER_SIZE];
    generate_noise(signal, BUFFER_SIZE);

    // Apply low-pass filter to signal
    lowpass_filter(signal, BUFFER_SIZE, 1000);

    // Output filtered signal
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", signal[i]);
    }

    return 0;
}
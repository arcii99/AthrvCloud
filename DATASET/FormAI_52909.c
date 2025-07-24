//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 4096; // Number of samples in audio buffer
    double f = 440.0; // Frequency of sine wave
    double *buffer = malloc(n * sizeof(double)); // Allocate memory for buffer
    
    // Generate sine wave
    for (int i = 0; i < n; i++) {
        buffer[i] = sin(2 * M_PI * f * i / n);
    }
    
    // Apply low pass filter
    double fc = 500.0; // Cutoff frequency
    double *output = calloc(n, sizeof(double)); // Allocate memory for output
    double K = tan(M_PI * fc / n); // Coefficient
    double a0 = 1 + K;
    double a1 = 2 * (1 - cos(M_PI/4)) / a0;
    double a2 = (1 - K) / a0;
    double b0 = (1 - cos(M_PI/4)) / a0;
    double b1 = 2 * b0 / a0;
    double b2 = b0;
    
    // Apply filter to buffer
    for (int i = 0; i < n; i++) {
        if (i < 2) { // Apply filter for first two samples
            output[i] = buffer[i];
        } else {
            output[i] = b0 * buffer[i] + b1 * buffer[i-1] + b2 * buffer[i-2] - a1 * output[i-1] - a2 * output[i-2];
        }
    }
    
    // Write audio buffer to file
    FILE *file = fopen("output.pcm", "wb");
    fwrite(output, sizeof(double), n, file);
    fclose(file);
    
    free(buffer); // Free memory
    free(output);
    
    return 0;
}
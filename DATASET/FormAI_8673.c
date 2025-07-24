//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>

#define BUFFER_SIZE 1024    // Buffer size for storing input and output data
#define SAMPLE_RATE 44100   // Audio sample rate in Hz
#define CUTOFF_FREQ 1000.0  // Cut-off frequency for low-pass filter in Hz

int main() {
    float input_buffer[BUFFER_SIZE];    // Buffer to store input audio
    float output_buffer[BUFFER_SIZE];   // Buffer to store output audio
    float fc = 2 * 3.14159 * CUTOFF_FREQ / SAMPLE_RATE;   // Calculate cut-off frequency for low-pass filter
    float a1 = -1.5610180758, a2 = 0.6413515385, b0 = 0.0000317665, b1 = 0.000063533, b2 = 0.0000317665;
    float x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;  // Variables to store previous samples for filtering

    printf("Enter %d samples of audio data:\n", BUFFER_SIZE);
    for (int i = 0; i < BUFFER_SIZE; i++) {
        scanf("%f", &input_buffer[i]);  // Read input audio samples from standard input
    }

    // Apply low-pass filter to input audio
    for (int i = 0; i < BUFFER_SIZE; i++) {
        float x0 = input_buffer[i];
        float y0 = b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        output_buffer[i] = y0;

        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
    }

    // Print filtered audio data to standard output
    printf("Filtered audio data:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", output_buffer[i]);
    }

    return 0;
}
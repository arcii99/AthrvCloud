//FormAI DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sample rate (44100 Hz) and the buffer size (1024)
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    float input[BUFFER_SIZE]; // Input buffer
    float output[BUFFER_SIZE]; // Output buffer
    float frequency = 440.0; // Starting frequency (A4)
    float phase = 0.0; // Starting phase
    float phase_increment = frequency * 2.0 * M_PI / SAMPLE_RATE; // Phase increment based on frequency

    // Loop through the buffers
    for (int i = 0; i < BUFFER_SIZE; i++) {
        // Generate a sine wave with the current frequency and phase
        input[i] = sin(phase);

        // Increment the phase
        phase += phase_increment;

        // If the phase is greater than 2π, wrap it back around to 0
        if (phase > 2.0 * M_PI) {
            phase -= 2.0 * M_PI;
        }

        // Apply a low-pass filter to the input signal
        if (i > 0) {
            output[i] = 0.5 * input[i] + 0.5 * input[i - 1]; // Simple moving average filter
        } else {
            output[i] = input[i];
        }

        // Apply a gain to the output signal
        output[i] *= 0.5;
    }

    // Write the output buffer to a file
    FILE *fp = fopen("output.raw", "wb");
    fwrite(output, sizeof(float), BUFFER_SIZE, fp);
    fclose(fp);

    return 0;
}
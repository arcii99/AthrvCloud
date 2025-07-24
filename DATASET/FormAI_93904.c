//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

// function to generate a sine wave
float sine_wave(float frequency, float time) {
    return sin(2*M_PI*frequency*time);
}

int main() {
    // allocate memory for buffer
    float* buffer = malloc(sizeof(float) * BUFFER_SIZE);
    if (!buffer) {
        printf("Error: unable to allocate memory\n");
        return 1;
    }

    // set values for processing
    float volume = 0.5;
    float frequency = 440.0;

    // loop through buffer and generate sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = sine_wave(frequency, (float)i / SAMPLE_RATE);
        buffer[i] *= volume;
    }

    // output buffer data to console
    printf("Output buffer:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", buffer[i]);
    }

    // free buffer memory
    free(buffer);

    return 0;
}
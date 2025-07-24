//FormAI DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define AMPLITUDE 32767

int main(void) {
    int samples = SAMPLE_RATE * 5; // 5 seconds of audio
    short *buffer = malloc(samples * sizeof(short)); // Allocate memory for buffer
    double phase_increment = 2.0 * M_PI * FREQUENCY / SAMPLE_RATE;
    double phase = 0;

    for (int i = 0; i < samples; i++) {
        buffer[i] = AMPLITUDE * sin(phase);
        phase += phase_increment;
        if (phase >= 2.0 * M_PI) {
            phase -= 2.0 * M_PI;
        }
    }

    // Write audio data to file
    FILE *file = fopen("output.pcm", "wb");
    fwrite(buffer, sizeof(short), samples, file);
    fclose(file);

    free(buffer); // Free memory allocated for buffer

    return 0;
}
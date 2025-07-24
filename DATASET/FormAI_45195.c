//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 32767
#define FREQUENCY 440

int main() {
    uint32_t num_samples = SAMPLE_RATE * 2; // 2 seconds of audio
    float *data = malloc(num_samples * sizeof(float));

    for (uint32_t i = 0; i < num_samples; i++) {
        data[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);
    }

    FILE *file = fopen("sound.raw", "wb");
    fwrite(data, sizeof(float), num_samples, file);
    fclose(file);

    free(data);
    return 0;
}
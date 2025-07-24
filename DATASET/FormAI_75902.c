//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 44100
#define PI 3.14159265358979323846

int main() {
    // initialize variables
    float frequency = 440.0; // in Hz
    float duration = 2.0; // in seconds
    float amplitude = 0.5;
    float phase = 0.0;

    // calculate needed parameters
    int num_samples = duration * SAMPLING_RATE;
    float time_step = 1.0 / SAMPLING_RATE;
    float angular_frequency = 2.0 * PI * frequency;

    // allocate memory for output array
    float* output = (float*) malloc(num_samples * sizeof(float));

    // generate waveform
    for (int i = 0; i < num_samples; i++) {
        float t = i * time_step;
        output[i] = amplitude * sin(angular_frequency * t + phase);
    }

    // write output to file
    FILE* file = fopen("output.raw", "wb");
    fwrite(output, sizeof(float), num_samples, file);
    fclose(file);

    // free memory
    free(output);

    return 0;
}
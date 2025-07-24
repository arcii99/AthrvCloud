//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main() {

    printf("\nRunning Cybernetic Signal Processor...\n");

    int sampling_rate = 44100;
    float freq = 1500;
    float phase = 0;
    float amplitude = 0.5;
    
    int duration = 5;
    int num_samples = sampling_rate * duration;

    float *buffer = (float *)malloc(num_samples * sizeof(float));

    for (int i = 0; i < num_samples; i++) {
        float time = (float)i / (float)sampling_rate;
        float sample = amplitude * sin(2 * PI * freq * time + phase);
        buffer[i] = sample;
    }

    printf("\nSignal Processed Successfully...\n");

    return 0;
}
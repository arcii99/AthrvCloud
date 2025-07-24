//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000
#define PI 3.14159265358979323846

void lowpass_filter(float cutoff, int num_samples, float* input, float* output) {
    float RC = 1.0 / (2 * PI * cutoff);
    float dt = 1.0 / SAMPLE_RATE;
    float alpha = dt / (RC + dt);
    
    output[0] = alpha * input[0];
    for (int i = 1; i < num_samples; i++) {
        output[i] = output[i-1] + alpha * (input[i] - output[i-1]);
    }
}

int main() {
    int num_samples = 1000;
    float cutoff = 1000.0;
    float input[num_samples];
    float output[num_samples];
    
    for (int i = 0; i < num_samples; i++) {
        input[i] = sin(2 * PI * 1000 * i / SAMPLE_RATE);
    }
    
    lowpass_filter(cutoff, num_samples, input, output);
    
    for (int i = 0; i < num_samples; i++) {
        printf("%f\n", output[i]);
    }
    
    return 0;
}
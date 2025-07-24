//FormAI DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265359

// Function to generate a sine wave
void gen_sine_wave(float freq, float *buffer, int n_samples) {
    float sample_rate = SAMPLE_RATE;
    float interval = sample_rate / freq;
    float angle_increment = (2.0f * PI) / interval;
    float angle = 0.0f;

    for (int i = 0; i < n_samples; i++) {
        buffer[i] = sinf(angle);
        angle += angle_increment;
    }
}

// Function to apply a low-pass filter
void apply_low_pass_filter(float *buffer, int n_samples) {
    float last_output = 0.0f;
    float alpha = 0.1f;

    for (int i = 0; i < n_samples; i++) {
        float current_output = (alpha * buffer[i]) + ((1 - alpha) * last_output);
        last_output = current_output;
        buffer[i] = current_output;
    }
}

int main() {
    // Generate a sine wave of 440hz
    int n_samples = BUFFER_SIZE;
    float buffer[BUFFER_SIZE];
    gen_sine_wave(440.0f, buffer, n_samples);

    // Apply a low-pass filter
    apply_low_pass_filter(buffer, n_samples);

    // Write output to file
    FILE *fp = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(float), n_samples, fp);
    fclose(fp);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359

int main() {
    // Generate a 1kHz sine wave of duration 1s
    int waveform_len = SAMPLE_RATE;
    float waveform[waveform_len];
    float frequency = 1000.0;
    for (int i = 0; i < waveform_len; i++) {
        waveform[i] = sin(2 * PI * frequency * i / SAMPLE_RATE);
    }

    // Apply a lowpass filter to the waveform
    float cutoff_freq = 500.0;
    float cutoff_normalized = cutoff_freq / SAMPLE_RATE;
    float rc = 1 / (2 * PI * cutoff_normalized);
    float dt = 1 / (float)SAMPLE_RATE;
    float alpha = dt / (dt + rc);
    float filtered_waveform[waveform_len];
    filtered_waveform[0] = waveform[0];
    for (int i = 1; i < waveform_len; i++) {
        filtered_waveform[i] = alpha * waveform[i] + (1 - alpha) * filtered_waveform[i-1];
    }

    // Write the generated waveform to a binary file
    FILE* fp = fopen("sine_wave.bin", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fwrite(waveform, sizeof(float), waveform_len, fp);
    fclose(fp);

    // Read in the generated waveform from the binary file
    float read_waveform[waveform_len];
    fp = fopen("sine_wave.bin", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fread(read_waveform, sizeof(float), waveform_len, fp);
    fclose(fp);

    // Print the original and filtered waveforms
    printf("Original waveform:\n");
    for (int i = 0; i < waveform_len; i++) {
        printf("%f ", waveform[i]);
    }
    printf("\n");

    printf("Filtered waveform:\n");
    for (int i = 0; i < waveform_len; i++) {
        printf("%f ", filtered_waveform[i]);
    }
    printf("\n");

    return 0;
}
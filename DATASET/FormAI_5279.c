//FormAI DATASET v1.0 Category: Audio processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359

float harmonic(int freq, int time, float amp, int sr) {
    float sample = 0.0;
    int i;
    int n_samples = time * sr;
    float delta = (float) (2 * PI * freq) / sr;

    for (i = 0; i < n_samples; i++) {
        sample += amp * sin(delta * i);
    }
    return sample;
}

float sawtooth(int freq, int time, float amp, int sr) {
    float sample = 0.0;
    int i;
    int n_samples = time * sr;
    float delta = (float) freq / sr;

    for (i = 0; i < n_samples; i++) {
        sample += amp * (2 * ((i * delta) - floor((i * delta) + 0.5)));
    }
    return sample;
}

int main() {
    int freq1 = 440, freq2 = 880, freq3 = 1320;
    int time = 5;
    float amp1 = 0.5, amp2 = 0.3, amp3 = 0.2;
    int sr = 44100;

    float harmonic_wave = harmonic(freq1, time, amp1, sr);
    float sawtooth_wave = sawtooth(freq2, time, amp2, sr);

    // Add two waves together
    float mixed_wave = harmonic_wave + sawtooth_wave;

    // Increase frequency
    float high_pitched_wave = harmonic(freq3, time, amp3, sr);

    // Add high pitched wave to mixed wave
    mixed_wave += high_pitched_wave;

    // Print the mixed wave
    printf("Mixed Wave:\n");
    int i;
    for (i = 0; i < time * sr; i++) {
        printf("%f\n", mixed_wave);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Audio processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

float square(float sample, float freq) {
    float period = SAMPLE_RATE / freq;
    if ((int)(sample / period) % 2 == 0) {
        return 1.0;
    }
    return -1.0;
}

float triangle(float sample, float freq) {
    float period = SAMPLE_RATE / freq;
    float phase = fmod(sample, period) / period;
    if (phase < 0.5) {
        return 4 * phase - 1;
    }
    return -4 * phase + 3;
}

float sine(float sample, float freq) {
    return sin(2 * PI * sample * freq / SAMPLE_RATE);
}

int main() {
    float freq = 440.0;
    float t = 0.0;
    float dt = 1.0 / SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE * 2; i++) {
        float sample = 0.5 * sine(t, freq) + 0.25 * square(t, freq) + 0.25 * triangle(t, freq);
        printf("%f\n", sample);
        t += dt;
    }

    return 0;
}
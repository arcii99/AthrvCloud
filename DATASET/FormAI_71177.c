//FormAI DATASET v1.0 Category: Digital signal processing ; Style: automated
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define PI 3.141592653589793

float sawtooth(float phase) {
    float x = fmod(2.0 * phase, 2.0) - 1.0;
    return x;
}

float triangular(float phase) {
    float x = fmod(phase, 2.0) - 1.0;
    if (x < 0.0) {
        x = 1.0 + x;
    }
    return 2.0 * x - 1.0;
}

int main() {
    float frequency = 440.0;
    float phase = 0.0;
    float phase_increment = (frequency / SAMPLE_RATE) * 2.0 * PI;

    for (int i = 0; i < SAMPLE_RATE; i++) {
        float value = sawtooth(phase);
        printf("%f\n", value);
        phase += phase_increment;
    }

    phase = 0.0;
    phase_increment = (frequency / SAMPLE_RATE) * 2.0 * PI;

    for (int i = 0; i < SAMPLE_RATE; i++) {
        float value = triangular(phase);
        printf("%f\n", value);
        phase += phase_increment;
    }

    return 0;
}
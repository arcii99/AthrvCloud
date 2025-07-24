//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define DURATION 5.0
#define AMPLITUDE 0.5

double sine_wave(double frequency, double time) {
    return AMPLITUDE * sin(2.0 * M_PI * frequency * time);
}

double square_wave(double frequency, double time) {
    return (sin(2.0 * M_PI * frequency * time) >= 0.0) ? AMPLITUDE : -AMPLITUDE;
}

double triangle_wave(double frequency, double time) {
    double period = 1.0 / frequency;
    double time_elapsed = fmod(time, period);
    double value = (2.0 / period) * time_elapsed;
    if (value < 1.0) {
        return AMPLITUDE * value;
    } else {
        return AMPLITUDE * (2.0 - value);
    }
}

int main() {
    double frequency = 440.0;
    double time_step = 1.0 / SAMPLE_RATE;
    double time = 0.0;
    double signal = 0.0;
    double(*wave_function)(double, double) = sine_wave;

    for (int i = 0; i < (int)(DURATION * SAMPLE_RATE); i++) {
        signal = wave_function(frequency, time);
        printf("%f\n", signal);
        time += time_step;
    }

    return 0;
}
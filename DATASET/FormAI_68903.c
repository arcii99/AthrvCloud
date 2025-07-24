//FormAI DATASET v1.0 Category: Audio processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    double frequency;
    double amplitude;
    double phase;
} sine_wave_t;

void generate_sine_wave(sine_wave_t *sine_wave, double frequency, double amplitude) {
    sine_wave->frequency = frequency;
    sine_wave->amplitude = amplitude;
    sine_wave->phase = 0.0;
}

void process_buffer(double buffer[], int buffer_size, sine_wave_t *sine_wave) {
    for (int i = 0; i < buffer_size; i++) {
        double sample = sine_wave->amplitude * sin(sine_wave->phase);
        buffer[i] = sample;
        sine_wave->phase += 2.0 * M_PI * sine_wave->frequency / (double) SAMPLE_RATE;
    }
}

int main() {
    double buffer[BUFFER_SIZE];
    sine_wave_t sine_wave;
    generate_sine_wave(&sine_wave, 440.0, 0.5);

    while (1) {
        process_buffer(buffer, BUFFER_SIZE, &sine_wave);
        fwrite(buffer, sizeof(double), BUFFER_SIZE, stdout);
    }

    return 0;
}
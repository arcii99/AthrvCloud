//FormAI DATASET v1.0 Category: Audio processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    int sample_rate;
    double frequency;
    double amplitude;
    double phase;
} sin_wave;

int main() {
    // initialize variables
    const int SAMPLE_RATE = 44100;
    const double FREQUENCY = 440;
    const double AMP = 0.75;
    const double PHASE = 0;

    sin_wave sine = {SAMPLE_RATE, FREQUENCY, AMP, PHASE};
    // calculate time and sample values
    const double DURATION = 5;
    const int NUM_SAMPLES = SAMPLE_RATE * DURATION;
    const double TIME_STEP = 1.0 / SAMPLE_RATE;

    // allocate memory for the sound buffer
    double *sound_buffer = malloc(NUM_SAMPLES * sizeof(double));
    if (!sound_buffer) {
        fprintf(stderr, "Failed to allocate memory for sound buffer.");
        exit(EXIT_FAILURE);
    }

    // generate sine wave data
    for (int i = 0; i < NUM_SAMPLES; i++) {
        double time = i * TIME_STEP;
        double value = sine.amplitude * sin(2 * PI * sine.frequency * time + sine.phase);
        sound_buffer[i] = value;
    }

    // apply amplitude envelope to sound data
    const double ATTACK_TIME = 0.1;
    const double RELEASE_TIME = 0.5;
    double *envelope = malloc(NUM_SAMPLES * sizeof(double));
    if (!envelope) {
        fprintf(stderr, "Failed to allocate memory for envelope.");
        exit(EXIT_FAILURE);
    }
    double attack_slope = 1.0 / (ATTACK_TIME * SAMPLE_RATE);
    double release_slope = -sine.amplitude * (attack_slope / (RELEASE_TIME * SAMPLE_RATE));
    bool is_releasing = false;
    double current_amplitude = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {
        double envelope_value;
        if (i < ATTACK_TIME * SAMPLE_RATE) {
            envelope_value = i * attack_slope;
        } else if (i > (DURATION - RELEASE_TIME) * SAMPLE_RATE) {
            if (!is_releasing) {
                is_releasing = true;
                current_amplitude = sound_buffer[i];
            }
            envelope_value = current_amplitude;
            current_amplitude += release_slope;
        } else {
            envelope_value = 1;
        }

        envelope[i] = envelope_value;
        sound_buffer[i] *= envelope_value;
    }

    // write sound data to file
    char *filename = "sin_wave.wav";
    FILE *sound_file = fopen(filename, "wb");
    if (!sound_file) {
        fprintf(stderr, "Failed to open file for writing.");
        exit(EXIT_FAILURE);
    }

    short int header[] = {0x4646, 0, 0, 0x4556, 0x207, 0, 0x1f40, 0, 0x10, 0x1, SAMPLE_RATE, SAMPLE_RATE, 0x10000, 0x61746164, 0};

    fwrite(header, sizeof(short int), 15, sound_file);

    for (int i = 0; i < NUM_SAMPLES; i++) {
        short int sample = (short int)(sound_buffer[i] * 32767.0);
        fwrite(&sample, sizeof(short int), 1, sound_file);
    }

    fclose(sound_file);
    free(sound_buffer);
    free(envelope);

    return 0;
}
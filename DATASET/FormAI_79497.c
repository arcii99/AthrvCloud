//FormAI DATASET v1.0 Category: Audio processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define SAMPLE_RATE
#define SAMPLE_RATE 44100

// Define ADSR settings
#define ATTACK_TIME 0.1
#define DECAY_TIME 0.2
#define RELEASE_TIME 1.0
#define SUSTAIN_LEVEL 0.7

// Define oscillator struct
typedef struct {
    float frequency;
    float phase;
} Oscillator;

// Define ADSR struct
typedef struct {
    float attack;
    float decay;
    float release;
    float sustain;
    float level;
    float timer;
} ADSR;

// Define wavetable
float wavetable[2048];

// Function to generate sine wave
void generate_sine_wave(float *buffer, int buffer_size, Oscillator *oscillator, ADSR *envelope) {
    float sample_rate = (float) SAMPLE_RATE;
    float attack_samples = envelope->attack * sample_rate;
    float decay_samples = envelope->decay * sample_rate;
    float release_samples = envelope->release * sample_rate;
    for (int i = 0; i < buffer_size; i++) {
        // Check if note is still being played
        if (envelope->level == 0) {
            break;
        }
        // Generate oscillator value
        oscillator->phase += oscillator->frequency / sample_rate;
        if (oscillator->phase > 1) {
            oscillator->phase -= 1;
        }
        float oscillator_value = wavetable[(int)(oscillator->phase * 2048)];
        // Apply ADSR envelope
        if (envelope->timer < attack_samples) {
            envelope->level = envelope->timer / attack_samples * envelope->sustain;
        } else if (envelope->timer < attack_samples + decay_samples) {
            envelope->level = (envelope->timer - attack_samples) / decay_samples * (envelope->level - envelope->sustain) + envelope->sustain;
        } else if (envelope->timer > buffer_size - release_samples) {
            envelope->level = (buffer_size - envelope->timer) / release_samples * envelope->sustain;
        }
        buffer[i] += oscillator_value * envelope->level;
        // Increment timer
        envelope->timer++;
    }
}

int main() {
    // Initialize oscillator and ADSR
    Oscillator oscillator = {445.0, 0};
    ADSR envelope = {ATTACK_TIME, DECAY_TIME, RELEASE_TIME, SUSTAIN_LEVEL, 1.0, 0};
    // Initialize wavetable
    for (int i = 0; i < 2048; i++) {
        wavetable[i] = sin(i * 2 * 3.1415 / 2048);
    }
    // Generate and print 1 second of audio
    int buffer_size = SAMPLE_RATE;
    float *buffer = malloc(buffer_size * sizeof(float));
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = 0;
    }
    generate_sine_wave(buffer, buffer_size, &oscillator, &envelope);
    for (int i = 0; i < buffer_size; i++) {
        printf("%f\n", buffer[i]);
    }
    // Free memory
    free(buffer);
    return 0;
}
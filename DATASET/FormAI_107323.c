//FormAI DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359

double envelope(double t, double attack, double decay, double sustain, double release) {
    if (t <= attack) {
        return t / attack;
    } else if (t <= attack + decay) {
        return 1 - (1 - sustain) * (t - attack) / decay;
    } else if (t <= release) {
        return sustain;
    } else {
        return sustain * exp(-(t - release) / release);
    }
}

double osc(double freq, double t) {
    return sin(2 * PI * freq * t);
}

double adsr(double freq, double t, double attack, double decay, double sustain, double release) {
    return envelope(t, attack, decay, sustain, release) * osc(freq, t);
}

int main() {
    double sound_duration = 2.0; // duration of generated sound in seconds
    double freq = 440.0; // frequency of the generated sound
    double attack = 0.1; // time (in seconds) for the attack phase of ADSR envelope
    double decay = 0.1; // time (in seconds) for the decay phase of ADSR envelope
    double sustain = 0.5; // sustain level of ADSR envelope
    double release = 0.2; // time (in seconds) for the release phase of ADSR envelope

    int num_samples = sound_duration * SAMPLE_RATE;
    double t = 0.0;
    double dt = 1.0 / SAMPLE_RATE;
    for (int i = 0; i < num_samples; i++) {
        double amplitude = adsr(freq, t, attack, decay, sustain, release);
        printf("%.6f\n", amplitude); // output sample value
        t += dt;
    }

    return 0;
}
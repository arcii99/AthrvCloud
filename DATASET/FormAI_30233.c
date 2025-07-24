//FormAI DATASET v1.0 Category: Audio processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cyberpunk audio processing program

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

float generateSawtooth(float frequency, float time) {
    float period = SAMPLE_RATE / frequency;
    return fmod(time, period) / period;
}

float generateSquare(float frequency, float time) {
    return generateSawtooth(frequency, time) < 0.5 ? -1.0 : 1.0;
}

float generateSine(float frequency, float time) {
    return sin(2 * PI * frequency * time);
}

float generateNoise() {
    return ((float) rand() / RAND_MAX) * 2 - 1;
}

int main() {
    float time = 0;
    float frequency = 1000;
    float amplitude = 0.5;
    float (*waveform)(float, float) = &generateSine;
    float cutoff = 5000;
    float resonance = 0;

    for (int i = 0; i < SAMPLE_RATE; i++) {
        float input = waveform(frequency, time);
        time += 1.0 / SAMPLE_RATE;
        
        // Apply low-pass filter
        float r = exp(-2 * PI * cutoff / SAMPLE_RATE);
        float c = 1 - r;
        float output = input * c + resonance * (1 - c);
        resonance = r * output + (1 - r) * resonance;

        // Apply distortion
        output = tanh(output * 10);

        // Apply reverb
        float delayTime = fmod(i, SAMPLE_RATE / 2);
        float delay = pow(0.7, delayTime * fmod(frequency, 200)) * amplitude;
        output = output + delay;

        // Apply tremolo
        output = output * (1 + 0.1 * sin(2 * PI * 2 * frequency * time));

        // Apply bit crusher
        output = round(output * 32) / 32;

        // Output sample
        printf("%.8f\n", output * amplitude);
    }

    return 0;
}
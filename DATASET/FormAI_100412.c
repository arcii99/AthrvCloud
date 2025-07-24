//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generate_sine_wave(double frequency, double duration, double amplitude, double phase, double *signal)
{
    int num_samples = (int)(duration * SAMPLE_RATE);
    double angular_frequency = 2 * PI * frequency;
    double time_step = 1 / SAMPLE_RATE;

    for (int i = 0; i < num_samples; i++) {
        double t = i * time_step;
        signal[i] = amplitude * sin(angular_frequency * t + phase);
    }
}

int main()
{
    double frequency = 440.0; // A4 note
    double duration = 1.0; // 1 second
    double amplitude = 0.5; // Half amplitude
    double phase = 0.0; // No phase shift

    double signal[44100];

    generate_sine_wave(frequency, duration, amplitude, phase, signal);

    // Print the first 10 samples
    for (int i = 0; i < 10; i++) {
        printf("%f\n", signal[i]);
    }

    return 0;
}
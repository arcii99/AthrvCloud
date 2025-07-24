//FormAI DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Declarations of functions
double sine_wave(double amplitude, double frequency, double phase, double time);
void print_samples(double *samples, uint32_t num_samples);

// Main function
int main(void)
{
    // Define constants
    const double amplitude = 0.5;
    const double frequency = 440.0;
    const double phase = 0.0;
    const double sample_rate = 44100.0;
    const uint32_t num_samples = 44100;

    // Calculate samples
    double samples[num_samples];
    for (uint32_t i = 0; i < num_samples; i++)
    {
        double time = (double)i / sample_rate;
        samples[i] = sine_wave(amplitude, frequency, phase, time);
    }

    // Print samples
    print_samples(samples, num_samples);

    return 0;
}

// Function to generate a sine wave sample
double sine_wave(double amplitude, double frequency, double phase, double time)
{
    return amplitude * sin(2.0 * M_PI * frequency * time + phase);
}

// Function to print audio samples
void print_samples(double *samples, uint32_t num_samples)
{
    for (uint32_t i = 0; i < num_samples; i++)
    {
        printf("%f\n", samples[i]);
    }
}
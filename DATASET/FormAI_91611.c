//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Generate a sinusoidal signal with a given amplitude, frequency, phase, and duration
void generate_signal(double amplitude, double frequency, double phase, int duration, double sample_rate, double *signal)
{
    for (int i = 0; i < duration * sample_rate; i++) {
        double t = (double)i / sample_rate;
        signal[i] = amplitude * sin(2.0 * PI * frequency * t + phase);
    }
}

// Apply a low-pass filter to a signal with a given cutoff frequency, using a Butterworth filter
void apply_low_pass_filter(double *signal, int duration, double sample_rate, double cutoff_frequency)
{
    double f0 = cutoff_frequency / sample_rate;
    double Q = 0.707106781186548; // Q factor of 0.707 is typical for a Butterworth filter

    double a0 = 1.0 + 2.0 * PI * f0 * Q + 4.0 * PI * PI * f0 * f0 * Q * Q;
    double a1 = 2.0 * (1.0 - 4.0 * PI * PI * f0 * f0 * Q * Q) / a0;
    double a2 = (1.0 - 2.0 * PI * f0 * Q + 4.0 * PI * PI * f0 * f0 * Q * Q) / a0;
    double b0 = 4.0 * PI * PI * f0 * f0 * Q * Q / a0;
    double b1 = 2.0 * b0 / a0;
    double b2 = b0;

    double y1 = 0.0, y2 = 0.0, x1 = 0.0, x2 = 0.0;

    for (int i = 0; i < duration * sample_rate; i++) {
        double x = signal[i];
        double y = (b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2) / a0;
        signal[i] = y;
        x2 = x1; x1 = x;
        y2 = y1; y1 = y;
    }
}

int main()
{
    int duration = 5; // signal duration in seconds
    double sample_rate = 44100; // sampling rate in Hz
    double amplitude = 1.0; // signal amplitude in volts
    double frequency = 1000; // signal frequency in Hz
    double phase = 0.0; // signal phase in radians
    double cutoff_frequency = 500; // cutoff frequency of the low-pass filter in Hz

    // Allocate memory for the signal
    int samples = duration * sample_rate;
    double *signal = (double *)malloc(samples * sizeof(double));
    if (signal == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }

    // Generate a sinusoidal signal
    generate_signal(amplitude, frequency, phase, duration, sample_rate, signal);

    // Apply a low-pass filter to the signal
    apply_low_pass_filter(signal, duration, sample_rate, cutoff_frequency);

    // Print the filtered signal
    printf("Sample\t Time (s)\t Amplitude (V)\n");
    for (int i = 0; i < samples; i++) {
        double t = (double)i / sample_rate;
        printf("%d\t %.6f\t %.6f\n", i, t, signal[i]);
    }

    // Free memory
    free(signal);

    return 0;
}
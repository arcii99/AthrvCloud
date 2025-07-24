//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave signal
void generate_sine_wave(float amplitude, float frequency, float time, float *signal)
{
    int i;

    for (i = 0; i < time; i++) {
        signal[i] = amplitude * sin(2 * PI * frequency * i / time);
    }
}

// Function to apply a low-pass filter
void apply_low_pass_filter(float *signal, float *filtered_signal, int time, float cutoff_frequency, float sampling_frequency)
{
    int i;
    float RC = 1 / (2 * PI * cutoff_frequency);
    float dt = 1 / sampling_frequency;
    float alpha = dt / (RC + dt);

    filtered_signal[0] = signal[0];
    for (i = 1; i < time; i++) {
        filtered_signal[i] = alpha * signal[i] + (1 - alpha) * filtered_signal[i - 1];
    }
}

int main()
{
    int time = 1000; // Time duration in msec
    float amplitude = 1; // Amplitude of sine wave signal
    float frequency = 50; // Frequency of sine wave signal
    float signal[time]; // Array to store the sine wave signal
    float filtered_signal[time]; // Array to store the filtered signal
    float sampling_frequency = 1000; // Sampling frequency in Hz
    float cutoff_frequency = 100; // Cutoff frequency for the low-pass filter in Hz
    int i;

    // Generate the sine wave signal
    generate_sine_wave(amplitude, frequency, time, signal);

    // Apply a low-pass filter to the signal
    apply_low_pass_filter(signal, filtered_signal, time, cutoff_frequency, sampling_frequency);

    // Print the original and filtered signal values
    printf("Time (ms)\tOriginal Signal\tFiltered Signal\n");
    for (i = 0; i < time; i++) {
        printf("%d\t%f\t%f\n", i, signal[i], filtered_signal[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
/* The Case of the Mysterious Signal */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 64 // number of samples in the signal
#define Fs 8000 // signal sampling frequency

// Function to generate a sinusoidal signal with a given frequency and duration
void generate_signal(double freq, double duration, double *signal)
{
    int n;

    for (n = 0; n < duration*Fs; n++) {
        signal[n] = sin(2*M_PI*freq*n/Fs);
    }
}

// Function to apply a Hamming window to a signal
void hamming_window(double *signal, double *windowed_signal, int window_size)
{
    int n;

    for (n = 0; n < window_size; n++) {
        windowed_signal[n] = signal[n] * (0.54 - 0.46*cos(2*M_PI*n/(window_size-1)));
    }
}

// Function to compute the Fast Fourier Transform (FFT) of a signal
void compute_fft(double *signal, int signal_size, double *real, double *imag)
{
    int k, n;

    for (k = 0; k < signal_size; k++) {
        real[k] = 0;
        imag[k] = 0;

        for (n = 0; n < signal_size; n++) {
            real[k] += signal[n] * cos(2*M_PI*k*n/signal_size);
            imag[k] -= signal[n] * sin(2*M_PI*k*n/signal_size);
        }
    }
}

// Function to find the peak frequency in a spectrum
double find_peak_frequency(double *spectrum, int spectrum_size)
{
    int k, peak_index;
    double peak_value = 0;

    for (k = 0; k < spectrum_size/2; k++) {
        if (spectrum[k] > peak_value) {
            peak_value = spectrum[k];
            peak_index = k;
        }
    }

    return (double) peak_index * Fs / spectrum_size;
}

int main()
{
    // The case of the mysterious signal: A strange signal has been detected in the airwaves of London, and it is up to DSP expert Sherlock Holmes to solve the mystery!

    double signal[N];
    double windowed_signal[N];
    double real[N], imag[N];
    double spectrum[N/2];
    double peak_freq;
    int i;

    // Generate the mysterious signal
    generate_signal(1000, 0.5, signal);
    generate_signal(2000, 0.5, signal+32);

    // Apply a Hamming window to the signal
    hamming_window(signal, windowed_signal, N);

    // Compute the FFT of the signal
    compute_fft(windowed_signal, N, real, imag);

    // Compute the spectrum magnitude
    for (i = 0; i < N/2; i++) {
        spectrum[i] = sqrt(real[i]*real[i] + imag[i]*imag[i]);
    }

    // Find the peak frequency in the spectrum
    peak_freq = find_peak_frequency(spectrum, N);

    // Output the results of the analysis
    printf("The mysterious signal has a peak frequency of %.2lf Hz\n", peak_freq);

    return 0;
}
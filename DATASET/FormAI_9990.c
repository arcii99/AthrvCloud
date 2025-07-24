//FormAI DATASET v1.0 Category: Audio processing ; Style: standalone
/*
* This program performs audio processing by using the Fast Fourier Transform (FFT)
* and applying a filter to the audio signal in the frequency domain.
* The program reads an audio file, applies a high-pass filter and saves the filtered audio to a new file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265359

// Function for performing the FFT
void fft(complex double *x, int n) {
    if (n <= 1) {
        return;
    }
    complex double *even = malloc(n/2 * sizeof(complex double));
    complex double *odd = malloc(n/2 * sizeof(complex double));

    for (int i = 0; i < n/2; i++) {
        even[i] = x[2*i];
        odd[i] = x[2*i+1];
    }

    fft(even, n/2);
    fft(odd, n/2);

    for (int i = 0; i < n/2; i++) {
        complex double t = cexp(-I * 2 * PI * i / n) * odd[i];
        x[i] = even[i] + t;
        x[i + n/2] = even[i] - t;
    }

    free(even);
    free(odd);
}

// Function for applying a high-pass filter to the audio signal in the frequency domain
void filter(complex double *x, int n, double cutoff) {
    for (int i = 0; i < n; i++) {
        double freq = i / (double)n;
        if (freq < cutoff || freq > 0.5) {
            x[i] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 4) {
        printf("Usage: ./audio_filter <input_file> <output_file> <cutoff_frequency>\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Error: could not open input file '%s'\n", argv[1]);
        return 1;
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        printf("Error: could not open output file '%s'\n", argv[2]);
        return 1;
    }

    // Get audio file size and sample rate
    fseek(input_file, 0, SEEK_END);
    long audio_size = ftell(input_file);
    rewind(input_file);
    int sample_rate = 44100;

    // Read audio data
    int num_samples = audio_size / sizeof(short);
    short *audio_data = malloc(audio_size);
    fread(audio_data, sizeof(short), num_samples, input_file);

    // Allocate memory for FFT input and output
    int fft_size = 1;
    while (fft_size < num_samples) {
        fft_size <<= 1;
    }
    complex double *fft_in = calloc(fft_size, sizeof(complex double));
    complex double *fft_out = calloc(fft_size, sizeof(complex double));

    // Copy audio data into FFT input
    for (int i = 0; i < num_samples; i++) {
        fft_in[i] = audio_data[i];
    }

    // Perform FFT
    fft(fft_in, fft_size);

    // Apply high-pass filter to FFT output
    double cutoff_freq = atof(argv[3]) / (sample_rate/2.0);
    filter(fft_in, fft_size, cutoff_freq);

    // Perform inverse FFT
    fft(fft_in, fft_size);
    for (int i = 0; i < num_samples; i++) {
        audio_data[i] = creal(fft_in[i]);
    }

    // Write filtered audio to output file
    fwrite(audio_data, sizeof(short), num_samples, output_file);

    // Free memory and close files
    free(audio_data);
    free(fft_in);
    free(fft_out);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FFT_SIZE 256

int main()
{
    FILE *file;
    char *filename = "audio.wav";
    short audioBuffer[FFT_SIZE];
    double real[FFT_SIZE];
    double imag[FFT_SIZE];
    double magnitude[FFT_SIZE/2];
    int i, j;

    // Open audio file
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read audio samples and perform FFT
    while (fread(audioBuffer, sizeof(short), FFT_SIZE, file)) {
        for (i = 0; i < FFT_SIZE; i++) {
            real[i] = (double)audioBuffer[i] / 32768.0; // Normalize sample values to [-1, 1]
            imag[i] = 0.0;
        }
        fft(real, imag, FFT_SIZE); // Perform FFT
        for (i = 0, j = FFT_SIZE/2; i < FFT_SIZE/2; i++, j++) {
            magnitude[i] = sqrt(real[i]*real[i] + imag[i]*imag[i]); // Calculate magnitude values
            magnitude[i] = 20 * log10(magnitude[i]); // Convert to dB
        }
        // Display magnitude values
        for (i = 0; i < FFT_SIZE/2; i++) {
            printf("%d %f\n", i, magnitude[i]);
        }
    }

    // Close audio file
    fclose(file);

    return 0;
}

// FFT implementation using Cooley-Tukey algorithm
void fft(double *real, double *imag, int n)
{
    int i, j, k;
    double tempReal, tempImag;
    double theta;
    double wReal, wImag;
    int bit;

    // Bit-reverse the input
    j = 0;
    for (i = 0; i < n-1; i++) {
        if (i < j) {
            tempReal = real[i];
            tempImag = imag[i];
            real[i] = real[j];
            imag[i] = imag[j];
            real[j] = tempReal;
            imag[j] = tempImag;
        }
        k = n/2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }

    // Perform FFT
    for (i = 2; i <= n; i *= 2) {
        for (j = 0; j < i/2; j++) {
            theta = 2 * M_PI * j / i;
            wReal = cos(theta);
            wImag = -sin(theta);
            for (k = j; k < n; k += i) {
                bit = k + i/2;
                tempReal = wReal * real[bit] - wImag * imag[bit];
                tempImag = wReal * imag[bit] + wImag * real[bit];
                real[bit] = real[k] - tempReal;
                imag[bit] = imag[k] - tempImag;
                real[k] += tempReal;
                imag[k] += tempImag;
            }
        }
    }
}
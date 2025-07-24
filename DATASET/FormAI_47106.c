//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>

/* This program computes the discrete Fourier transform of a real-valued 
   sequence using the Fast Fourier Transform algorithm. The input values are 
   read from a file and the resulting complex frequency spectrum is output to 
   another file. */

#define N 1024         /* number of samples in the input sequence */
#define Fs 8000        /* sampling frequency in Hz */
#define f0 500         /* frequency of the sine wave in Hz */
#define PI 3.14159265 /* the value of pi */

int main()
{
    /* Read the input sequence from a file */
    FILE *inputfile = fopen("input.txt", "r");
    float x[N];
    for (int i = 0; i < N; i++)
        fscanf(inputfile, "%f", &x[i]);
    fclose(inputfile);

    /* Compute the discrete Fourier transform using FFT */
    float real[N], imag[N];
    for (int k = 0; k < N; k++) {
        real[k] = imag[k] = 0;
        for (int n = 0; n < N; n++) {
            real[k] += x[n] * cos(2 * PI * k * n / N);
            imag[k] -= x[n] * sin(2 * PI * k * n / N);
        }
    }

    /* Output the complex frequency spectrum to a file */
    FILE *outputfile = fopen("output.txt", "w");
    for (int k = 0; k < N; k++)
        fprintf(outputfile, "%.2f + j%.2f\n", real[k], imag[k]);
    fclose(outputfile);

    return 0;
}
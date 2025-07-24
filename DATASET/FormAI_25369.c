//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 256
#define FS 44100
#define FREQ 2000

int main() {
    double input[N], output[N], window[N], freq_mag;
    double freq_rad = 2*M_PI*FREQ/FS;
    int i, j;

    /* Generate a test signal */
    for (i = 0; i < N; i++) {
        input[i] = 0.5*sin(2*M_PI*100*i/FS) + sin(freq_rad*i);
    }

    /* Apply a Hann window */
    for (i = 0; i < N; i++) {
        window[i] = 0.5*(1 - cos(2*M_PI*i/(N-1)));
        input[i] *= window[i];
    }

    /* Compute the DFT for each frequency */
    for (i = 0; i < N; i++) {
        output[i] = 0;
        for (j = 0; j < N; j++) {
            output[i] += input[j]*cos(2*M_PI*i*j/N) - input[j]*sin(2*M_PI*i*j/N);   
        }
    }

    /* Find the magnitude of the desired frequency */
    freq_mag = sqrt(pow(output[N*FREQ/FS], 2) + pow(output[N*FREQ/FS + 1], 2));

    /* Print the results */
    printf("Input Signal:\n");
    for (i = 0; i < N; i++) {
        printf("%.3f ", input[i]);
    }

    printf("\n\nDFT Output:\n");
    for (i = 0; i < N; i++) {
        printf("%.3f ", output[i]);
    }

    printf("\n\nFrequency Magnitude: %.3f\n", freq_mag);

    return 0;
}
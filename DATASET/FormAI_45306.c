//FormAI DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fs 44100 // Sampling frequency
#define F0 440 // Frequency of sinusoidal signal
#define N 88200 // Number of samples

int main() {
    float x[N], y[N];
    float a = 0.99; // Loop filter coefficient
    float b = 1 - a; // Feedforward coefficient
    float xn, yn;
    int i;

    // Generate input signal
    for (i = 0; i < N; i++) {
        x[i] = sin(2 * M_PI * F0 / Fs * i);
    }

    // Apply low-pass filter
    for (i = 0; i < N; i++) {
        xn = x[i];
        yn = b * xn + a * (yn - xn);
        y[i] = yn;
    }

    // Print output signal to file
    FILE *fp;
    fp = fopen("output.txt", "w+");
    for (i = 0; i < N; i++) {
        fprintf(fp, "%.6f\n", y[i]);
    }
    fclose(fp);

    printf("Digital signal processing example program complete!\n");

    return 0;
}
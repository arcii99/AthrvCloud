//FormAI DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int i, j;
    int N = 1000; // number of data points
    double f1 = 100; // frequency of signal 1
    double f2 = 200; // frequency of signal 2
    double Fs = 1000; // sampling frequency
    double T = 1 / Fs; // sampling period
    double t[N]; // time vector
    double x[N]; // signal vector
    double w[N]; // window vector
    double y[N]; // signal with added noise

    // Generate time and signal vectors
    for(i = 0; i < N; i++)
    {
        t[i] = i * T;
        x[i] = cos(2 * PI * f1 * t[i]) + sin(2 * PI * f2 * t[i]);
    }

    // Generate window vector
    for(i = 0; i < N; i++)
    {
        w[i] = 0.5 - 0.5 * cos(2 * PI * i / (N - 1));
    }

    // Apply window to signal
    for(i = 0; i < N; i++)
    {
        x[i] = x[i] * w[i];
    }

    // Add noise to the signal
    srand(time(NULL)); // seed for random number generator
    double sigma = 0.1; // standard deviation of noise
    for(i = 0; i < N; i++)
    {
        double noise = sigma * ((double)rand() / (double)RAND_MAX - 0.5);
        y[i] = x[i] + noise;
    }

    // Compute power spectral density using Welch method
    int L = 100; // number of data points per segment
    int K = N / L; // number of segments
    double P[K][L]; // power spectral density
    double f[K][L]; // frequency vector
    double S[K][L]; // periodogram
    double Savg[L]; // average periodogram
    double PSD[L]; // power spectral density estimate
    for(j = 0; j < L; j++)
    {
        Savg[j] = 0;
        for(i = 0; i < K; i++)
        {
            int n = i * L + j;
            S[i][j] = pow(fabs(y[n]), 2);
            Savg[j] += S[i][j];
            f[i][j] = i * Fs / N + j * Fs / (N * L);
        }
        Savg[j] /= K;
        PSD[j] = 2 / (Fs * Savg[j]) * pow(fabs(Savg[j]), 2);
    }

    // Print power spectral density
    printf("Frequency (Hz)\tPower Spectral Density (W/Hz)\n");
    for(i = 0; i < L; i++)
    {
        printf("%lf\t%lf\n", f[0][i], PSD[i]);
    }

    return 0;
}
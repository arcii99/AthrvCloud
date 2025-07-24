//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define N 256

int main()
{
    float real[N], imag[N], signal[N];
    float angle, magnitude, freq, phase;
    int i, j;

    for(i = 0; i < N; i++) {
        signal[i] = sin(2 * PI * i * 3 / N) + sin(2 * PI * i * 6 / N) + sin(2 * PI * i * 12 / N);
    }

    for(i = 0; i < N; i++) {
        real[i] = 0;
        imag[i] = 0;

        for(j = 0; j < N; j++) {
            angle = 2 * PI * i * j / N;
            real[i] += signal[j] * cos(angle);
            imag[i] -= signal[j] * sin(angle);
        }

        magnitude = sqrt(real[i] * real[i] + imag[i] * imag[i]);
        freq = i;
        phase = atan2(imag[i], real[i]);

        printf("Frequency: %.2f Hz\nMagnitude: %.2f\nPhase: %.2f\n\n", freq, magnitude, phase);
    }

    return 0;
}
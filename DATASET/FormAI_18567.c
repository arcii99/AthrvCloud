//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Simulate a square wave signal with sampling rate Fs and frequency F */
void square_wave(int Fs, int F, double duration, int *output)
{
    int samples = (int) (duration * Fs);
    double T = 1.0 / F;
    double t = 0.0;
    int i;
    for (i = 0; i < samples; ++i) {
        if (fmod(t, T) < T / 2.0) {
            output[i] = 1;
        } else {
            output[i] = -1;
        }
        t += 1.0 / Fs;
    }
}

/* Apply a low-pass filter to the input signal */
void low_pass_filter(int *input, int Fs, int cutoff, int *output)
{
    double RC = 1.0 / (2.0 * PI * cutoff);
    double alpha = 1.0 / (1.0 + RC * Fs);
    int i;
    output[0] = input[0];
    for (i = 1; i < Fs; ++i) {
        output[i] = alpha * input[i] + (1.0 - alpha) * output[i - 1];
    }
}

int main()
{
    int Fs = 44100;
    int F = 1000;
    double duration = 0.5;
    int cutoff = 500;

    int input[Fs];
    int output_s[Fs];
    int output_lpf[Fs];

    square_wave(Fs, F, duration, input);
    low_pass_filter(input, Fs, cutoff, output_lpf);

    printf("Input signal:\n");
    int i;
    for (i = 0; i < Fs; ++i) {
        printf("%d ", input[i]);
    }
    printf("\n");

    printf("Low-pass filtered signal:\n");
    for (i = 0; i < Fs; ++i) {
        printf("%d ", output_lpf[i]);
    }
    printf("\n");

    return 0;
}
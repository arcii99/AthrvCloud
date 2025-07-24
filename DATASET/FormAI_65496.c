//FormAI DATASET v1.0 Category: Digital signal processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fs 1000 // Sampling frequency
#define N 1024 // Number of samples

int main()
{
    int i;
    float x[N];
    float y[N];
    float t[N];
    float f1 = 10; // First frequency component
    float f2 = 100; // Second frequency component
    float A1 = 1; // Amplitude of first frequency component
    float A2 = 0.5; // Amplitude of second frequency component
    float noise_mag = 0.2; // Magnitude of noise

    // Generate sinusoidal signal composed of two frequency components and noise
    for (i = 0; i < N; i++) {
        t[i] = (float)i / Fs;

        x[i] = A1 * sin(2 * M_PI * f1 * t[i]) + A2 * sin(2 * M_PI * f2 * t[i]);

        x[i] += noise_mag * ((float)rand() / RAND_MAX - 0.5); // Add noise
    }

    // Perform FFT on input signal
    float re[N];
    float im[N];
    float mag[N/2];

    for (i = 0; i < N; i++) {
        re[i] = x[i];
        im[i] = 0.0;
    }

    fft(re, im, N, 0); // Perform FFT

    for (i = 0; i < N/2; i++) {
        mag[i] = sqrt(re[i]*re[i] + im[i]*im[i]); // Calculate magnitude spectrum
    }

    // Perform low-pass filtering at 50 Hz
    float cutoff_freq = 50;
    float wc = 2 * M_PI * cutoff_freq / Fs;
    float alpha = sin(wc) / (2 * cos(wc) + sin(wc));
    float beta = (1 - cos(wc)) / 2;

    float xh[N];
    float yh[N];

    xh[0] = x[0];
    for (i = 1; i < N; i++) {
        xh[i] = alpha * (x[i] + x[i-1]) + beta*xh[i-1];
    }

    // Perform FFT on filtered signal
    for (i = 0; i < N; i++) {
        re[i] = xh[i];
        im[i] = 0.0;
    }

    fft(re, im, N, 0); // Perform FFT

    for (i = 0; i < N/2; i++) {
        mag[i] = sqrt(re[i]*re[i] + im[i]*im[i]); // Calculate magnitude spectrum
    }

    // Perform biquad high-pass filtering at 2 Hz
    float f = 2;
    float w0 = 2 * M_PI * f / Fs;
    float Q = 5;
    float alpha2 = sin(w0) / (2*Q);

    float b0 = (1 + cos(w0)) / 2;
    float b1 = -1 - cos(w0);
    float b2 = (1 + cos(w0)) / 2;
    float a0 = 1 + alpha2;
    float a1 = -2 * cos(w0);
    float a2 = 1 - alpha2;

    float x2[N];
    float y2[N];

    x2[0] = xh[0];
    x2[1] = xh[1];
    y2[0] = 0;
    y2[1] = 0;

    for (i = 2; i < N; i++) {
        x2[i] = xh[i];

        y2[i] = (b0/a0)*x2[i] + (b1/a0)*x2[i-1] + (b2/a0)*x2[i-2]
                - (a1/a0)*y2[i-1] - (a2/a0)*y2[i-2];
    }

    // Print output signal to file
    FILE *fp;
    fp = fopen("output.txt", "w");
    for (i = 0; i < N; i++) {
        fprintf(fp, "%f\n", y2[i]);
    }
    fclose(fp);

    return 0;
}

void fft(float *re, float *im, int n, int inverse)
{
    int i, j, k, n1, n2, a;
    float c, s, t1, t2;

    j = 0;
    n1 = n - 1;

    // Bit-reverse input data
    for (i = 0; i < n1; i++) {
        if (i < j) {
            t1 = re[j];
            t2 = im[j];
            re[j] = re[i];
            im[j] = im[i];
            re[i] = t1;
            im[i] = t2;
        }
        k = n/2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }

    // Perform FFT
    n1 = 0;
    n2 = 1;

    for (i = 0; i < log2(n); i++) {
        n1 = n2;
        n2 *= 2;

        for (j = 0; j < n1; j++) {
            a = 0;
            for (k = j*n2; k < j*n2 + n2/2; k++) {
                c = cos(2 * M_PI * a / n2);
                s = sin(2 * M_PI * a / n2);
                t1 = c * re[k + n2/2] - s * im[k + n2/2];
                t2 = s * re[k + n2/2] + c * im[k + n2/2];
                re[k + n2/2] = re[k] - t1;
                im[k + n2/2] = im[k] - t2;
                re[k] += t1;
                im[k] += t2;
                a += n1;
            }
        }
    }

    // Scale output by 1/N if inverse FFT is performed
    if (inverse) {
        for (i = 0; i < n; i++) {
            re[i] /= n;
            im[i] /= n;
        }
    }
}
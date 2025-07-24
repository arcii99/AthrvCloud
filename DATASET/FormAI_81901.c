//FormAI DATASET v1.0 Category: Digital signal processing ; Style: accurate
#include <stdio.h>
#include <math.h>

#define N 1024   // Length of input signal
#define PI 3.141592653589793

// Function to compute Discrete Fourier Transform (DFT)
void dft(double x[], double Xr[], double Xi[]) {
    int k, n;
    for (k = 0; k < N; k++) {
        Xr[k] = 0;
        Xi[k] = 0;
        for (n = 0; n < N; n++) {
            Xr[k] += x[n] * cos(2 * PI * k * n / N);
            Xi[k] -= x[n] * sin(2 * PI * k * n / N);
        }
    }
}

// Function to compute Inverse Discrete Fourier Transform
void idft(double Xr[], double Xi[], double x[]) {
    int k, n;
    for (n = 0; n < N; n++) {
        x[n] = 0;
        for (k = 0; k < N; k++) {
            x[n] += Xr[k] * cos(2 * PI * k * n / N)
                  - Xi[k] * sin(2 * PI * k * n / N);
        }
        x[n] /= N;
    }
}

int main() {
    double x[N], Xr[N], Xi[N];  // input signal and its DFT
    int n;

    // Generate input signal
    for (n = 0; n < N; n++) {
        x[n] = sin(2 * PI * n / N);   // sine wave with frequency N/2 and amplitude 1
    }

    // Compute DFT
    dft(x, Xr, Xi);

    // Modify DFT here
    for (n = 0; n < N; n++) {
        Xr[n] *= exp(-n*PI/N);   // attenuation of frequency components
    }

    // Compute Inverse DFT
    idft(Xr, Xi, x);

    // Write input and output signals to file
    FILE *fp;
    fp = fopen("output.txt", "w");
    fprintf(fp, "Input Signal:\n");
    for (n = 0; n < N; n++) {
        fprintf(fp, "%lf\n", x[n]);
    }
    fprintf(fp, "Output Signal:\n");
    for (n = 0; n < N; n++) {
        fprintf(fp, "%lf\n", x[n]);
    }
    fclose(fp);

    return 0;
}
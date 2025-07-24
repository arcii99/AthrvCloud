//FormAI DATASET v1.0 Category: Audio processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to compute Fast Fourier Transform
void fft(double* x, double* y, int n) {
    if (n <= 1) {
        return;
    }
    double* odd_x = malloc((n/2) * sizeof(double));
    double* odd_y = malloc((n/2) * sizeof(double));
    double* even_x = malloc((n/2) * sizeof(double));
    double* even_y = malloc((n/2) * sizeof(double));

    // Splitting into odd and even parts
    for (int i = 0; i < n/2; i++) {
        even_x[i] = x[2*i];
        even_y[i] = y[2*i];
        odd_x[i] = x[2*i+1];
        odd_y[i] = y[2*i+1];
    }

    // Recursively computing FFT of odd and even parts
    fft(even_x, even_y, n/2);
    fft(odd_x, odd_y, n/2);

    // Combining the results of odd and even parts
    for (int k = 0; k < n/2; k++) {
        double c = cos(2 * PI * k / n);
        double s = sin(2 * PI * k / n);
        double t_re = c * odd_x[k] - s * odd_y[k];
        double t_im = c * odd_y[k] + s * odd_x[k];
        x[k] = even_x[k] + t_re;
        y[k] = even_y[k] + t_im;
        x[k + n/2] = even_x[k] - t_re;
        y[k + n/2] = even_y[k] - t_im;
    }

    // Freeing the temporary arrays
    free(odd_x);
    free(odd_y);
    free(even_x);
    free(even_y);
}

int main() {
    int n = 8;
    double x[n];
    double y[n];

    // Initializing the input sequence
    for (int i = 0; i < n; i++) {
        x[i] = sin(2 * PI * i / n);
        y[i] = 0.0;
    }

    // Computing the FFT
    fft(x, y, n);

    // Printing the results
    printf("The FFT of input sequence is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f + i%f\n", x[i], y[i]);
    }
    return 0;
}
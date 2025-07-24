//FormAI DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define N 8

void dft(int *input, double *output) {
    for (int k = 0; k < N; ++k) {
        double real = 0, imaginary = 0;
        for (int n = 0; n < N; ++n) {
            real += input[n] * cos(2 * PI * n * k / N);
            imaginary -= input[n] * sin(2 * PI * n * k / N);
        }
        output[k] = sqrt(real * real + imaginary * imaginary);
    }
}

int main() {
    int input[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    double output[N];
    dft(input, output);
    for (int k = 0; k < N; ++k) {
        printf("Magnitude of bin %d: %f\n", k, output[k]);
    }
    return 0;
}
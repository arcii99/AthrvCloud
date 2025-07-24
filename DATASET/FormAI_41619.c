//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the Discrete Fourier Transform (DFT) for given set of input data
void DFT(int N, double input[], double real[], double imag[]) {
    for (int k = 0; k < N; k++) {
        real[k] = imag[k] = 0.0;
        for (int n = 0; n < N; n++) {
            real[k] += input[n] * cos(2 * PI * k * n / N);
            imag[k] -= input[n] * sin(2 * PI * k * n / N);
        }
    }
}

int main() {
    int N;
    printf("Enter number of samples: ");
    scanf("%d", &N);

    double input[N];

    printf("Enter %d input samples: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &input[i]);
    }

    double real[N], imag[N];

    // Call DFT function to calculate DFT of input data
    DFT(N, input, real, imag);

    printf("\nDFT output:\n");
    for (int k = 0; k < N; k++) {
        printf("X[%d] = %.2lf + j%.2lf\n", k, real[k], imag[k]);
    }

    return 0;
}
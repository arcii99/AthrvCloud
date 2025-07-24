//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define global constants */
#define PI 3.14159265358979323846
#define N 10

/* Define function to compute the discrete Fourier transform */
void DFT(double x[], double Xr[], double Xi[]) {
    int k, n;
    double c, s, Wr, Wi;

    for (k = 0; k < N; k++) {
        Xr[k] = 0;
        Xi[k] = 0;

        for (n = 0; n < N; n++) {
            c = cos(2 * PI * k * n / N);
            s = -sin(2 * PI * k * n / N);

            Xr[k] += x[n] * c;
            Xi[k] += x[n] * s;
        }
    }
}

/* Define function to print complex numbers */
void printComplex(double Xr[], double Xi[]) {
    int k;

    printf("X(k) = ");

    for (k = 0; k < N; k++) {
        printf("%.2f + %.2fi, ", Xr[k], Xi[k]);
    }

    printf("\n");
}

/* Define main function */
int main() {
    double x[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double Xr[N];
    double Xi[N];

    DFT(x, Xr, Xi);
    printComplex(Xr, Xi);

    return 0;
}
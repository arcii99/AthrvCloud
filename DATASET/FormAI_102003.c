//FormAI DATASET v1.0 Category: Digital signal processing ; Style: medieval
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 8

int main() {
    int i, j;
    double x[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    double real[N], imag[N], mag[N];
    double w[N][N], y_r[N], y_i[N];
    
    // Generate twiddle factor matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            w[i][j] = cos(2 * PI * i * j / N) - sin(2 * PI * i * j / N);
        }
    }
    
    // Perform FFT
    for (i = 0; i < N; i++) {
        real[i] = x[i];
        imag[i] = 0;
        
        for (j = 0; j < N; j++) {
            y_r[i] += real[j] * w[i][j] - imag[j] * w[i][j];
            y_i[i] += real[j] * w[i][j] + imag[j] * w[i][j];
        }
        
        mag[i] = sqrt(y_r[i]*y_r[i] + y_i[i]*y_i[i]);
    }
    
    // Print results
    printf("Input: ");
    for (i = 0; i < N; i++) {
        printf("%.1f\t", x[i]);
    }
    
    printf("\nFFT: ");
    for (i = 0; i < N; i++) {
        printf("%.1f + %.1fi\t", y_r[i], y_i[i]);
    }
    
    printf("\nMagnitude: ");
    for (i = 0; i < N; i++) {
        printf("%.1f\t", mag[i]);
    }
    
    return 0;
}
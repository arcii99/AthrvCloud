//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define N 128 // input sample size
#define M 10 // filter coefficients
 
int main(void){
    int n, m;
    double in[N], out[N], h[M];
 
    // Initialize input samples
    for (n = 0; n < N; n++)
        in[n] = sin(2.0 * M_PI * 10.0 * n / N) +
                cos(2.0 * M_PI * 20.0 * n / N) +
                0.5 * sin(2.0 * M_PI * 50.0 * n / N);
 
    // Initialize filter coefficients
    for (m = 0; m < M; m++)
        h[m] = sin(M_PI * (m - M / 2.0)) / (M_PI * (m - M / 2.0)) *
               (0.54 - 0.46 * cos(2.0 * M_PI * m / M));
 
    // Apply filter to input signal
    for (n = 0; n < N; n++) {
        double sum = 0.0;
        for (m = 0; m < M; m++) {
            if (n - m >= 0)
                sum += h[m] * in[n - m];
        }
        out[n] = sum;
    }
 
    // Display results
    for (n = 0; n < N; n++)
        printf("%f\n", out[n]);
 
    return 0;
}
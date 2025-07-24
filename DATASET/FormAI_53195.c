//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// Define FIR filter coefficients
double h[5] = { 0.1, 0.2, 0.3, 0.2, 0.1 };

// Define input signal
double x[11] = { 1.0, 2.0, 3.0, 4.0, 5.0, 4.0, 3.0, 2.0, 1.0, 0.0, -1.0 };

// Define output signal buffer
double y[11];

int main()
{
    // Initialize output signal to zero
    for (int i = 0; i < 11; i++) {
        y[i] = 0.0;
    }

    // Apply FIR filter
    for (int n = 4; n < 11; n++) {
        // Compute output sample
        for (int k = 0; k < 5; k++) {
            y[n] += h[k] * x[n - k];
        }
    }

    // Print input signal
    printf("Input Signal:\n");
    for (int i = 0; i < 11; i++) {
        printf("%f\n", x[i]);
    }

    // Print output signal
    printf("\nOutput Signal:\n");
    for (int i = 0; i < 11; i++) {
        printf("%f\n", y[i]);
    }

    // Generate sine wave signal
    double z[32];
    for (int n = 0; n < 32; n++) {
        z[n] = sin(2 * PI * n / 32);
    }

    // Compute DFT of sine wave signal
    double Xr[32], Xi[32];
    for (int k = 0; k < 32; k++) {
        Xr[k] = 0.0;
        Xi[k] = 0.0;
        for (int n = 0; n < 32; n++) {
            Xr[k] += z[n] * cos(2 * PI * k * n / 32);
            Xi[k] -= z[n] * sin(2 * PI * k * n / 32);
        }
    }

    // Print DFT of sine wave signal
    printf("\nDFT of Sine Wave Signal:\n");
    for (int k = 0; k < 32; k++) {
        printf("%f + j%f\n", Xr[k], Xi[k]);
    }

    return 0;
}
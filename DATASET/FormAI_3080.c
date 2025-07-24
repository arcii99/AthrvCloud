//FormAI DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

// Define filter coefficients for a low-pass filter
#define A0 0.0112805
#define A1 0.0112805
#define A2 0.0
#define B1 1.91151
#define B2 -0.914975

int main()
{
    // Define input signal
    double x[] = {6, 8, 7, 9, 5, 3, 1, 5, 4, 6};

    // Define output signal
    double y[10];

    // Implement low-pass filter using difference equation
    for (int n = 2; n < 10; ++n)
    {
        y[n] = A0*x[n] + A1*x[n-1] + A2*x[n-2] - B1*y[n-1] - B2*y[n-2];
    }

    // Print input and output signals
    printf("Input Signal: ");
    for (int i = 0; i < 10; ++i)
    {
        printf("%.2f ", x[i]);
    }
    printf("\n");

    printf("Output Signal: ");
    for (int i = 0; i < 10; ++i)
    {
        printf("%.2f ", y[i]);
    }
    printf("\n");

    return 0;
}
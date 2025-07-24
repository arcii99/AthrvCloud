//FormAI DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024        // Define signal length
#define Fs 10000      // Define sampling frequency
#define Fc 1000       // Define cutoff frequency
#define PI 3.14159265 // Define PI value

int main()
{
    float xn[N], yn[N];     // Define input signal and filter output signal arrays
    float dt = 1.0 / Fs;     // Calculate sampling interval
    float RC = 1.0 / (2 * PI * Fc); // Calculate time constant of low-pass filter
    float alpha = dt / (RC + dt);  // Calculate filter gain
    float y_prev = 0;       // Define previous output sample value

    // Generate input signal (sine wave)
    for (int n = 0; n < N; n++)
    {
        xn[n] = sin(2 * PI * 1000 * n / Fs);
    }

    // Low-pass filter the input signal using first-order recursive filter
    for (int n = 0; n < N; n++)
    {
        yn[n] = alpha * xn[n] + (1 - alpha) * y_prev;
        y_prev = yn[n];
    }

    // Print the input signal and filter output signal values
    printf("n\tInput Signal\Filter Output\n");
    for (int n = 0; n < N; n++)
    {
        printf("%d\t%f\t%f\n", n, xn[n], yn[n]);
    }

    return 0;
}
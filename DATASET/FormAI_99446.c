//FormAI DATASET v1.0 Category: Digital signal processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

int main()
{
    int i;
    double theta, signal[100], filter[100], output[100];

    // generate input signal
    for (i = 0; i < 100; i++) {
        theta = 2 * PI * i / 100;
        signal[i] = 5 * (sin(2 * theta) + sin(5 * theta) + sin(7 * theta));
    }

    // define the low-pass filter
    for (i = 0; i < 100; i++) {
        filter[i] = sin(0.1 * PI * (i - 50)) / (PI * (i - 50));
    }
    filter[50] = 0.1;

    // apply the filter to the input signal
    for (i = 0; i < 100; i++) {
        output[i] = 0;
        int j;
        for (j = 0; j < 100; j++) {
            if (i - j >= 0 && i - j < 100) {
                output[i] += signal[j] * filter[i - j];
            }
        }
    }

    // print the output signal
    for (i = 0; i < 100; i++) {
        printf("%f\n", output[i]);
    }

    return 0;
}
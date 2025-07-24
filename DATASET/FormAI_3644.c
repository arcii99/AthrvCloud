//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    // define input values and arrays
    float inputSignal[10] = {1, 2, -1, 4, 5, -3, -2, 0, 6, 8};
    float outputSignal[10];
    float filterCoeff[5] = {0.2, 0.2, 0.2, 0.2, 0.2}; // Low pass filter coefficients

    // apply low pass filter
    for (int i = 0; i < 10; i++) {
        outputSignal[i] = 0;

        for (int j = 0; j < 5; j++) {
            if (i - j >= 0) {
                outputSignal[i] += inputSignal[i - j] * filterCoeff[j];
            }
        }
    }

    // print input and output signals
    printf("Input Signal: ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", inputSignal[i]);
    }

    printf("\nOutput Signal: ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", outputSignal[i]);
    }

    // generate sine wave
    float sineWave[100];
    float frequency = 5; // signal frequency
    float amplitude = 2; // signal amplitude
    float phase = PI/4; // signal phase shift

    for (int i = 0; i < 100; i++) {
        sineWave[i] = amplitude * sin(2 * PI * frequency * i / 100 + phase);
    }

    // print sine wave
    printf("\nSine Wave:\n");
    for (int i = 0; i < 100; i++) {
        printf("%.2f ", sineWave[i]);
    }

    return 0;
}
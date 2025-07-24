//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100      // Number of samples
#define PI 3.1415  // Value of pi

// Generate input signal
void generateInputSignal(float *inputSignal)
{
    for(int i = 0; i < N; i++)
    {
        inputSignal[i] = 5.0 * sin(2 * PI * i * 10.0 / N) + 2.5 * sin(2 * PI * i * 30.0 / N) + 1.0 * sin(2 * PI * i * 50.0 / N);
    }
}

// Implement a 2-point moving average filter
void movingAverageFilter(float *inputSignal, float *outputSignal)
{
    for(int i = 1; i < N-1; i++)
    {
        outputSignal[i] = (inputSignal[i-1] + inputSignal[i] + inputSignal[i+1]) / 3.0;
    }
    // Copy the first and last elements of the input signal to the output signal
    outputSignal[0] = inputSignal[0];
    outputSignal[N-1] = inputSignal[N-1];
}

int main()
{
    float inputSignal[N];    // Declare input signal
    float outputSignal[N];   // Declare output signal

    // Generate input signal
    generateInputSignal(inputSignal);

    // Implement a 2-point moving average filter
    movingAverageFilter(inputSignal, outputSignal);

    // Print input and output signals
    printf("Input Signal \t Output Signal\n");
    for(int i = 0; i < N; i++)
    {
        printf("%.2f \t\t %.2f\n", inputSignal[i], outputSignal[i]);
    }

    return 0;
}
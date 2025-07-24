//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constant values
#define PI 3.14159265358979323846
#define SAMPLING_RATE 8000
#define FREQUENCY 2000
#define TIME_SEC 5
#define AMPLITUDE 10000

int main()
{
    // Generate sine wave signal
    int n = SAMPLING_RATE * TIME_SEC;
    double signal[n];
    for(int i = 0; i < n; i++)
    {
        signal[i] = AMPLITUDE * sin(2 * PI * FREQUENCY * i / SAMPLING_RATE);
    }
    
    // Add noise to signal
    double noise[n];
    for(int i = 0; i < n; i++)
    {
        noise[i] = ((double)rand() / (double)RAND_MAX) - 0.5;
        signal[i] += noise[i];
    }
    
    // Apply high-pass filter to remove low frequencies
    double alpha = 0.9;
    double output[n];
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            output[i] = signal[i];
        }
        else
        {
            output[i] = alpha * output[i-1] + alpha * (signal[i] - signal[i-1]);
        }
    }
    
    // Print output signal
    printf("Output Signal:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%f\n", output[i]);
    }
    
    return 0;
}
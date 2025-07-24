//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multivariable
#include <stdio.h>

#define BUFFER_SIZE 1000

int main()
{
    int buffer[BUFFER_SIZE];
    int input, output;
    float gain = 2.5, alpha = 0.7;

    // Initialize buffer with zeros
    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = 0;
    }

    while(1)
    {
        // Read input data from some source
        scanf("%d", &input);

        // Apply gain to input signal
        output = input * gain;

        // Apply low-pass filter to output
        for(int i = BUFFER_SIZE-1; i > 0; i--)
        {
            buffer[i] = buffer[i-1];
        }

        buffer[0] = output;

        for(int i = 1; i < BUFFER_SIZE; i++)
        {
            buffer[i] = buffer[i] + alpha * (buffer[i-1] - buffer[i]);
        }

        // Output filtered signal
        printf("Filtered signal: %d\n", buffer[BUFFER_SIZE-1]);
    }

    return 0;
}
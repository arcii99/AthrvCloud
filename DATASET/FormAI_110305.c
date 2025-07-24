//FormAI DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>

#define MAX_INPUT_SIZE 1000

int main()
{
    int input_samples[MAX_INPUT_SIZE]; // Array to store input samples
    int output_samples[MAX_INPUT_SIZE]; // Array to store output samples
    int num_samples; // Number of input samples
    int i; // Loop counter

    // Read input samples
    printf("Enter number of samples: ");
    scanf("%d", &num_samples);

    printf("Enter %d samples: ", num_samples);
    for(i=0; i<num_samples; i++)
    {
        scanf("%d", &input_samples[i]);
    }

    // Apply low pass filter
    output_samples[0] = input_samples[0];
    for(i=1; i<num_samples; i++)
    {
        output_samples[i] = (output_samples[i-1] + input_samples[i])/2;
    }

    // Print output samples
    printf("Output samples: ");
    for(i=0; i<num_samples; i++)
    {
        printf("%d ", output_samples[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>

// Define the signal array
#define SIGNAL_LENGTH 10
float signal[SIGNAL_LENGTH] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

// Define the filter array
#define FILTER_LENGTH 3
float filter[FILTER_LENGTH] = {0.2, 0.6, 0.2};

// Define the output array
float output[SIGNAL_LENGTH];

// Apply the filter to the signal
void apply_filter()
{
    int i, j;
    float sum;

    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        sum = 0.0;

        for (j = 0; j < FILTER_LENGTH; j++)
        {
            if ((i-j) >= 0)
            {
                sum += signal[i-j] * filter[j];
            }
        }

        output[i] = sum;
    }
}

int main()
{
    int i;

    // Print the initial signal
    printf("Input Signal:\n");
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        printf("%f ", signal[i]);
    }
    printf("\n");

    // Print the filter coefficients
    printf("Filter Coefficients:\n");
    for (i = 0; i < FILTER_LENGTH; i++)
    {
        printf("%f ", filter[i]);
    }
    printf("\n");

    // Apply the filter to the signal
    apply_filter();

    // Print the output signal after applying the filter
    printf("Output Signal:\n");
    for (i = 0; i < SIGNAL_LENGTH; i++)
    {
        printf("%f ", output[i]);
    }
    printf("\n");

    return 0;
}
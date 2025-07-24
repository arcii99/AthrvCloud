//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>

#define SAMPLES 10

void main()
{
    int signal[SAMPLES] = {2, 3, 6, 8, 7, 5, 4, 2, 1, 0};
    int result[SAMPLES] = {0};
    int i, j;
    int filter[3] = {1, 2, 1};

    for (i = 0; i < SAMPLES; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            if (i + j >= 0 && i + j < SAMPLES)
            {
                result[i] += signal[i+j] * filter[j+1];
            }
        }
        result[i] /= 4;
    }

    printf("Original Signal: ");
    for (i = 0; i < SAMPLES; i++)
    {
        printf("%d ", signal[i]);
    }

    printf("\nFiltered Signal: ");
    for (i = 0; i < SAMPLES; i++)
    {
        printf("%d ", result[i]);
    }
}
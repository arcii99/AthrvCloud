//FormAI DATASET v1.0 Category: Digital signal processing ; Style: imaginative
#include <stdio.h>

#define ARRAY_SIZE 4
#define M_PI 3.14159265358979323846

int main()
{
    float buffer_in[ARRAY_SIZE] = {0.25, 0.5, 1.0, 0.75};
    float buffer_out[ARRAY_SIZE] = {0};
    float filter[3] = {
        0.1*(M_PI/2), 
        0.8*(M_PI/2),
        0.1*(M_PI/2)
    };
    int i, j;

    // Apply filter to input buffer
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i-j >= 0)
            {
                buffer_out[i] += filter[j] * buffer_in[i-j];
            }
        }
    }

    // Print input and output buffers
    printf("Input buffer: ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%f ", buffer_in[i]);
    }
    printf("\n");

    printf("Output buffer: ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%f ", buffer_out[i]);
    }
    printf("\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform Discrete Fourier Transform
void perform_dft(int *input, int n, int *real, int *img)
{
    // Loop through each frequency
    for (int k = 0; k < n; k++)
    {
        // Initialize real and imaginary components
        real[k] = img[k] = 0;

        // Loop through each sample point
        for (int i = 0; i < n; i++)
        {
            real[k] += input[i] * cos((2 * M_PI * i * k) / n);
            img[k] -= input[i] * sin((2 * M_PI * i * k) / n);
        }
    }
}

int main()
{
    int input[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    // Declare arrays to store real and imaginary components
    int real[n];
    int img[n];

    perform_dft(input, n, real, img);

    // Print the results
    for (int k = 0; k < n; k++)
    {
        printf("Frequency %d: Amplitude = %d, Phase = %d\n",
               k, 2 * sqrt(real[k] * real[k] + img[k] * img[k]) / n,
               atan2(img[k], real[k]) * 180 / M_PI);
    }

    return 0;
}
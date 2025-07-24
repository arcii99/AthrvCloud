//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    // Initializing variables
    int num_samples = 1000;
    int frequency = 50;
    float amplitude = 2.0;
    float sampling_rate = 1000.0;

    float time_array[num_samples];
    float signal[num_samples];

    // Generate time array
    for (int i = 0; i < num_samples; i++)
    {
        time_array[i] = (float)i / sampling_rate;
    }

    // Generate signal
    for (int i = 0; i < num_samples; i++)
    {
        signal[i] = amplitude * sin(2 * PI * frequency * time_array[i]);
    }

    // Perform FFT on signal using Cooley-Tukey algorithm
    int k, n;
    int num_bits = log2(num_samples);

    for (int i = 0; i < num_samples; i++)
    {
        // Reorder data to bit-reversed order
        k = 0;
        for (int j = 0; j < num_bits; j++)
        {
            if (i & (1 << j))
            {
                k |= 1 << (num_bits - 1 - j);
            }
        }

        if (k > i)
        {
            float temp = signal[i];
            signal[i] = signal[k];
            signal[k] = temp;
        }
    }

    // Perform FFT
    for (int i = 1; i <= num_bits; i++)
    {
        int power = pow(2, i);
        int half_power = pow(2, i - 1);

        float real_coefficient = cos(2 * PI / power);
        float imaginary_coefficient = sin(2 * PI / power);

        float real_part, imaginary_part;
        float previous_real_part, previous_imaginary_part;

        for (int j = 0; j < half_power; j++)
        {
            real_part = 1;
            imaginary_part = 0;

            for (int m = 0; m < num_samples / power; m++)
            {
                n = j + m * half_power + half_power;

                previous_real_part = real_part;
                previous_imaginary_part = imaginary_part;

                real_part = previous_real_part * real_coefficient - previous_imaginary_part * imaginary_coefficient;
                imaginary_part = previous_real_part * imaginary_coefficient + previous_imaginary_part * real_coefficient;

                float temp_real = real_part * signal[n] - imaginary_part * signal[n + half_power];
                float temp_imaginary = real_part * signal[n + half_power] + imaginary_part * signal[n];

                signal[n] = signal[j + m * half_power] - temp_real;
                signal[n + half_power] = signal[j + m * half_power + half_power] - temp_imaginary;
                signal[j + m * half_power] += temp_real;
                signal[j + m * half_power + half_power] += temp_imaginary;
            }
        }
    }

    // Print results
    for (int i = 0; i < num_samples; i++)
    {
        printf("%f, %f\n", time_array[i], signal[i]);
    }

    return 0;
}
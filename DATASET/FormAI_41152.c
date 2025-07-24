//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <math.h>

#define LENGTH 256 // Length of input signal
#define PI 3.14159 // Value of pi

int main()
{
    int i, j, k;
    double input[LENGTH];
    double output_real[LENGTH/2];
    double output_imag[LENGTH/2];
    double angle;

    // Generate input signal
    for(i = 0; i < LENGTH; i++)
    {
        input[i] = sin(2 * PI * 50 * i) + sin(2 * PI * 120 * i);
    }

    // Perform Fourier Transform
    for(i = 0; i < LENGTH/2; i++)
    {
        output_real[i] = 0;
        output_imag[i] = 0;
        for(j = 0; j < LENGTH; j++)
        {
            angle = 2 * PI * i * j / LENGTH;
            output_real[i] += input[j] * cos(angle);
            output_imag[i] += input[j] * sin(angle);
        }
    }

    // Print output
    printf("Frequency (Hz)\tMagnitude\n");
    for(i = 0; i < LENGTH/2; i++)
    {
        printf("%lf\t%lf\n", i * 2.0 * PI / LENGTH, 2.0 * sqrt(output_real[i]*output_real[i] + output_imag[i]*output_imag[i])/LENGTH);
    }

    return 0;
}
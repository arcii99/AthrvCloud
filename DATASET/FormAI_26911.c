//FormAI DATASET v1.0 Category: Digital signal processing ; Style: imaginative
#include <stdio.h>

// Define the size of the input data array
#define DATA_SIZE 10

// Define a function to compute the discrete Fourier transform of the input signal
void compute_dft(double *input_data, double *output_data_real, double *output_data_imag)
{
    int i, j;
    double real_sum, imag_sum;
    double theta, delta_theta;

    // Compute the DFT for each frequency bin
    for (i = 0; i < DATA_SIZE; i++) {
        // Initialize the real and imaginary sums to zero
        real_sum = 0;
        imag_sum = 0;
        
        // Compute the DFT for this frequency bin
        for (j = 0; j < DATA_SIZE; j++) {
            // Compute the angle for this sample
            theta = 2 * 3.14159265 * i * j / DATA_SIZE;

            // Compute the real and imaginary parts of the complex exponential
            output_data_real[i] += input_data[j] * cos(theta);
            output_data_imag[i] -= input_data[j] * sin(theta);
        }
    }
}

int main()
{
    // Define the input data array
    double input_data[DATA_SIZE] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    // Define the output data arrays
    double output_data_real[DATA_SIZE] = {0};
    double output_data_imag[DATA_SIZE] = {0};

    // Compute the DFT of the input signal
    compute_dft(input_data, output_data_real, output_data_imag);

    // Print the output data arrays
    printf("Real Part\tImaginary Part\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%f\t%f\n", output_data_real[i], output_data_imag[i]);
    }

    return 0;
}
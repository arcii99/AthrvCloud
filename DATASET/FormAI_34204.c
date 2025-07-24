//FormAI DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <math.h>

//Let's find the real DFT of a signal of length 8
//with an input signal of {1, 2, 3, 4, 5, 6, 7, 8}

int main()
{
    //Declare variables
    int n, k;
    double real[8], imag[8], signal[8]={1, 2, 3, 4, 5, 6, 7, 8};
    
    //Loop through all sample points
    for (k = 0; k < 8; k++) {
        real[k] = 0;
        imag[k] = 0;

        //Perform the fourier transform on the signal
        for (n = 0; n < 8; n++) {
            real[k] += signal[n] * cos(2 * M_PI * n * k / 8);
            imag[k] -= signal[n] * sin(2 * M_PI * n * k / 8);
        }

        //Print out the results for each frequency bin
        printf("For k = %d:\n", k);
        printf("Real: %f\n", real[k]);
        printf("Imaginary: %f\n", imag[k]);
        printf("\n");
    }

    return 0;
}
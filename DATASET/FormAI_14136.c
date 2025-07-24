//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
//This program performs a simple FIR filter on a signal
#include <stdio.h>
#include <stdlib.h>

//Filter coefficients and signal input
float b[] = {0.1, 0.2, 0.3, 0.4, 0.5};
float x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float y[10];

int main()
{
    //Loop over each sample in the input signal
    for (int n = 0; n < 10; n++) {

        //Compute the FIR filter output for this sample
        y[n] = 0;
        for (int k = 0; k < 5; k++) {
            if(n-k < 0){
                continue;
            }
            y[n] += b[k] * x[n-k];
        }

        //Print the output to the console
        printf("x[%d] = %f, y[%d] = %f\n", n, x[n], n, y[n]);
    }

    return 0;
}
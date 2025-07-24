//FormAI DATASET v1.0 Category: Digital signal processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int n;
    printf("Enter the number of samples in the signal: ");
    scanf("%d", &n);
    float real[n], imag[n];
    float x[n], freq[n], amplitude[n], phase[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter sample %d: ", i+1);
        scanf("%f", &x[i]);
    }

    //DFT
    for(int k=0; k<n; k++)
    {
        real[k] = 0;
        imag[k] = 0;
        for(int j=0; j<n; j++)
        {
            real[k] += x[j] * cos(2*PI*k*j/n);
            imag[k] -= x[j] * sin(2*PI*k*j/n);
        }
        freq[k] = k * 1.0 / n;
        amplitude[k] = sqrt(pow(real[k],2) + pow(imag[k],2));
        phase[k] = atan2(imag[k], real[k]);
    }

    //Printing the output
    printf("\n\nFrequency\tAmplitude\tPhase\n");
    for(int i=0; i<n/2; i++)
    {
        printf("%f\t%f\t%f\n", freq[i], amplitude[i], phase[i]);
    }

    return 0;
}
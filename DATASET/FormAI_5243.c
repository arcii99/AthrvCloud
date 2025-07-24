//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
/* This is a complex style DSP program that implements a digital filter */

#include <stdio.h>
#include <math.h>

/* Define constants */
#define N 100
#define PI 3.14159265358979323846

/* Declare function prototypes */
void calcCoeffs(float[], float[]);
void applyFilter(float[], float[]);
void printResult(float[]);

/* Define global variables */
float inputSignal[N];
float outputSignal[N];

int main()
{
    /* Generate input signal */
    for(int i=0; i<N; i++) {
        inputSignal[i] = sin(i*2*PI*10/N);
    }
    
    /* Calculate filter coefficients */
    float b[3] = {0.1, 0.2, 0.1};
    float a[3] = {1.0, -0.6, 0.4};
    calcCoeffs(b, a);
    
    /* Apply filter to input signal */
    applyFilter(b, a);
    
    /* Print results */
    printResult(outputSignal);
    
    return 0;
}

/* Function to calculate filter coefficients */
void calcCoeffs(float b[], float a[])
{
    float x[3] = {1.0, 0.0, 0.0};
    float y[3] = {0.0, 0.0, 0.0};
    
    /* Calculate a0 */
    float a0 = a[0];
    for(int i=1; i<3; i++) {
        a0 -= a[i]*x[i];
    }
    
    /* Normalize coefficients */
    for(int i=0; i<3; i++) {
        b[i] /= a0;
        a[i] /= a0;
    }
}

/* Function to apply filter */
void applyFilter(float b[], float a[])
{
    for(int i=0; i<N; i++) {
        outputSignal[i] = b[0]*inputSignal[i]
                          + b[1]*inputSignal[i-1]
                          + b[2]*inputSignal[i-2]
                          - a[1]*outputSignal[i-1]
                          - a[2]*outputSignal[i-2];
    }
}

/* Function to print results */
void printResult(float outputSignal[])
{
    for(int i=0; i<N; i++) {
        printf("%f\n", outputSignal[i]);
    }
}
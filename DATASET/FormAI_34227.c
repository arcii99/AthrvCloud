//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define circuit parameters */
#define R1 1000.0
#define R2 2000.0
#define C1 0.000001
#define C2 0.000002

/* Define generic functions to calculate circuit values */
double impedance(double R, double C, double freq) {
    return 1.0/(2*M_PI*freq*C)+R;
}

double phase_shift(double R, double C, double freq) {
    return atan(1/(2*M_PI*freq*R*C))*180/M_PI;
}

int main() {
    double freq;
    printf("Enter the frequency of the input signal in Hz: ");
    scanf("%lf", &freq);
    
    /* Calculate circuit values */
    double Z1 = impedance(R1,C1,freq);
    double Z2 = impedance(R2,C2,freq);
    double total_impedance = Z1*Z2/(Z1+Z2);
    double phase = phase_shift(R1,C1,freq) - phase_shift(R2,C2,freq);
    
    printf("Total impedance of circuit: %e ohms\n", total_impedance);
    printf("Phase shift of circuit: %lf degrees\n", phase);
    
    return 0;
}
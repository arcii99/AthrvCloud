//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Constants
#define PI 3.14159265359

// Define Functions
double complex_impedance(double r, double c, double f) {
    double w = 2 * PI * f;
    double xc = 1 / (w * c);
    double z = sqrt(pow(r, 2) + pow(xc, 2));
    return z;
}

double phase_shift(double r, double c, double f) {
    double w = 2 * PI * f;
    double xc = 1 / (w * c);
    double tan_phi = xc / r;
    double phi = atan(tan_phi);
    return phi;
}

void circuit_simulator(double r, double c, double f) {
    double z = complex_impedance(r, c, f);
    double phi = phase_shift(r, c, f);
    
    printf("Frequency: %.2f Hz\n", f);
    printf("Impedance (Z): %.2f Ohms\n", z);
    printf("Phase Shift (phi): %.2f degrees\n", phi * 180 / PI);
}

int main() {
    double r = 1000;    // Resistor value (in Ohms)
    double c = 1E-6;    // Capacitor value (in Farads)
    double f = 1000;    // Frequency (in Hz)
    
    circuit_simulator(r, c, f);
    
    return 0;
}
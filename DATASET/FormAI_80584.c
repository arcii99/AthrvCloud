//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 5

// Function for calculating the resistance of a resistor
double resistor(double r) {
    return r;
}

// Function for calculating the reactance of a capacitor
double capacitor(double c, double f) {
    double reactance = 1 / (2 * M_PI * f * c);
    return reactance;
}

// Function for calculating the reactance of an inductor
double inductor(double l, double f) {
    double reactance = 2 * M_PI * f * l;
    return reactance;
}

// Function for calculating the total impedance of a circuit
double impedance(double r, double xc, double xl) {
    double total = sqrt(pow(r, 2) + pow((xc - xl), 2));
    return total;
}

// Main function
int main() {
    double r, c, l, f, xc, xl, z;
    printf("Enter the resistance (in ohms): ");
    scanf("%lf", &r);
    printf("Enter the capacitance (in farads): ");
    scanf("%lf", &c);
    printf("Enter the inductance (in henrys): ");
    scanf("%lf", &l);
    printf("Enter the frequency (in hertz): ");
    scanf("%lf", &f);

    xc = capacitor(c, f);
    xl = inductor(l, f);
    z = impedance(r, xc, xl);

    printf("\nXc = %lf\n", xc);
    printf("Xl = %lf\n", xl);
    printf("Z = %lf\n", z);

    return 0;
}
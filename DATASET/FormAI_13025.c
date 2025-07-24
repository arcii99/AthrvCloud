//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <math.h>

// This program simulates a simple RC circuit in a romantic style

// Define value of resistance
#define R 100

// Function to calculate voltage across capacitor
double voltage(double t, double C) {
    return exp(-t/(R*C));
}

int main() {
    double t, C, Vc;
    printf("My dear, please enter the value of capacitance (in farads): ");
    scanf("%lf", &C);
    printf("My love, please enter the time (in seconds): ");
    scanf("%lf", &t);
    Vc = voltage(t, C);
    printf("My darling, the voltage across the capacitor is %.2f volts ❤️\n", Vc);
    return 0;
}
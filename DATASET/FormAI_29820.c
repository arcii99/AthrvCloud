//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the voltage in a circuit
double voltage(double R, double C, double t, double V) {
    return (V * (1 - exp(-1 / (R * C) * t)));
}

// Function to calculate the current in a circuit
double current(double R, double C, double t, double V) {
    return (V / R * exp(-1 / (R * C) * t));
}

int main() {
    double R, C, V, t, vt, it;

    // Take input from user
    printf("Enter resistance value (in ohms): ");
    scanf("%lf", &R);
    printf("Enter capacitance value (in farads): ");
    scanf("%lf", &C);
    printf("Enter voltage value (in volts): ");
    scanf("%lf", &V);
    printf("Enter time value (in seconds): ");
    scanf("%lf", &t);

    // Calculate voltage and current
    vt = voltage(R, C, t, V);
    it = current(R, C, t, V);

    // Display results
    printf("Result:\n");
    printf("Voltage at time %lf seconds: %lf volts\n", t, vt);
    printf("Current at time %lf seconds: %lf amps\n", t, it);

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define circuit parameters
#define R1 1000
#define R2 2200
#define C 0.000001
#define VCC 5

// Define function to calculate voltage across capacitor
double calculateVoltage(double time) {
    double voltage = VCC*(1 - exp(-time/(R1*C)));
    voltage *= exp(-time/(R2*C));
    return voltage;
}

int main() {
    // Define time increment and maximum time
    double timeIncrement = 0.001;
    double maxTime = 1;

    // Loop through each time increment and calculate voltage across capacitor
    for (double t = 0; t <= maxTime; t += timeIncrement) {
        double voltage = calculateVoltage(t);
        printf("Time: %f seconds, Voltage: %f volts\n", t, voltage);
    }

    return 0;
}
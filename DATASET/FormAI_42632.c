//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define circuit constants
#define R1 5
#define R2 10
#define C1 2 * pow(10, -6)
#define C2 pow(10, -6)
#define VIN 5

// Define function to calculate voltage across capacitor C2
double voltageC2(double t);

// Define function to calculate voltage across resistor R2
double voltageR2(double t);

int main()
{
    // Define time variables
    double t = 0;   // Current time
    double T = 0.01;    // Time step
    int n = 1000;    // Number of time steps

    // Define output file
    FILE *output;
    output = fopen("circuitsim.txt", "w");

    // Print column headings
    fprintf(output, "Time\tVoltage C2\tVoltage R2\n");

    // Run simulation for n time steps
    for (int i = 0; i <= n; i++)
    {
        // Calculate voltage across capacitor C2 and resistor R2
        double Vc2 = voltageC2(t);
        double Vr2 = voltageR2(t);

        // Print results to output file
        fprintf(output, "%0.2f\t%0.2f\t%0.2f\n", t, Vc2, Vr2);

        // Increment time
        t += T;
    }

    // Close output file
    fclose(output);

    // Print success message
    printf("Circuit simulation complete. Results written to circuitsim.txt");

    return 0;
}

// Function to calculate voltage across capacitor C2
double voltageC2(double t)
{
    double Vc2 = VIN * (1 - exp(-t / (R1 * C1))) * exp(-t / (R2 * C2));
    return Vc2;
}

// Function to calculate voltage across resistor R2
double voltageR2(double t)
{
    double Vr2 = VIN * (1 - exp(-t / (R1 * C1))) * (1 - exp(-t / (R2 * C2)));
    return Vr2;
}
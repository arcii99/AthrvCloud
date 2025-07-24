//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
/* This is a classical circuit simulator example program that models a simple circuit with a voltage source and three resistors in series.
 * It uses Kirchhoff's laws to calculate the currents and voltages across each component.
 * The program defines resistances and voltages as double precision floating point numbers.
 * Written by [Your Name], [Your Email], [Your Institution], [Date].
 */

#include <stdio.h>
#include <math.h>

int main() {
    // Define the resistances of the circuit.
    double R1 = 1000.0;
    double R2 = 2200.0;
    double R3 = 3300.0;

    // Define the voltage source of the circuit.
    double V = 12.0;

    // Calculate the total resistance of the circuit.
    double R_total = R1 + R2 + R3;

    // Calculate the current flowing through the circuit.
    double I = V / R_total;

    // Calculate the voltage drops across each resistor.
    double V1 = I * R1;
    double V2 = I * R2;
    double V3 = I * R3;

    // Print the results to the console.
    printf("Circuit Simulation Results:\n");
    printf("Total Resistance (Ω): %f\n", R_total);
    printf("Current (A): %f\n", I);
    printf("Voltage Drop Across Resistor 1 (V): %f\n", V1);
    printf("Voltage Drop Across Resistor 2 (V): %f\n", V2);
    printf("Voltage Drop Across Resistor 3 (V): %f\n", V3);

    return 0;
}
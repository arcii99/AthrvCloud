//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
/*
C Classical Circuit Simulator

Description: This program simulates the behavior of electronic circuits with classical components like resistors, capacitors, and inductors.
The user enters the values of the circuit elements, and the program calculates the output voltage and current for a given input voltage or current source.

Author: [Your Name]
Date: [Date of creation]

*/
#include <stdio.h>
#include <math.h>

// Function to calculate the output voltage and current of a circuit with a given input voltage/current
void circuit_simulator(double R, double L, double C, double Vin, double Iin, double f, double tstep, double tmax) {
    // Initialize variables
    double Vout = 0;
    double Iout = 0;
    double Vprev = 0;
    double Iprev = 0;
    double w = 2 * M_PI * f;

    // Loop through time steps
    for (double t = 0; t < tmax; t += tstep) {
        // Calculate impedance of circuit elements
        double Xc = 1 / (w * C);
        double Xl = w * L;
        double Ztot = R + Xl - Xc;

        // Calculate output voltage/current
        if (Vin != 0) {
            Iout = (Vin - Vprev) / Ztot;
            Vout = Vin - Iout * R;
        } else {
            Vout = Iin * Ztot + Vprev;
            Iout = Iin;
        }

        // Update previous values
        Vprev = Vout;
        Iprev = Iout;

        // Print output values
        printf("Time: %.4f s    ", t);
        printf("Voltage: %.4f V    ", Vout);
        printf("Current: %.4f A\n", Iout);
    }
}

int main() {
    // Define circuit parameters
    double R = 1000;    // Resistor value in Ohms
    double L = 10e-3;   // Inductor value in Henries
    double C = 1e-6;    // Capacitor value in Farads
    double Vin = 10;    // Input voltage in Volts
    double Iin = 0;     // Input current in Amperes
    double f = 1000;    // Circuit frequency in Hertz
    double tstep = 1e-5;    // Time step in seconds
    double tmax = 1e-2; // Maximum simulation time in seconds

    // Call function to simulate circuit
    circuit_simulator(R, L, C, Vin, Iin, f, tstep, tmax);

    return 0;
}
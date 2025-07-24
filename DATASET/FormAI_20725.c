//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the impedance of a capacitor
double calculateCapacitanceImpedance(double freq, double capacitance) {
    return 1 / (2 * PI * freq * capacitance);
}

// Function to calculate the impedance of an inductor
double calculateInductanceImpedance(double freq, double inductance) {
    return 2 * PI * freq * inductance;
}

// Function to calculate the voltage drop across a resistor
double calculateVoltageDrop(double current, double resistance) {
    return current * resistance;
}

// Starting frequency in Hz
double startFreq = 1;

// Ending frequency in Hz
double endFreq = 1000000;

// Step size in Hz for frequency sweep
double stepSize = 1000;

// Capacitance in Farads
double capacitance = 0.000001;

// Inductance in Henries
double inductance = 0.1;

// Resistance in Ohms
double resistance = 1000;

int main() {
    double freq;
    double impedance;
    double voltageDrop;
    double current;

    printf("Frequency (Hz)\tImpedance (Ohms)\tVoltage Drop (Volts)\n");
    for (freq = startFreq; freq <= endFreq; freq += stepSize) {
        // Calculate the impedance of the circuit at this frequency
        impedance = calculateCapacitanceImpedance(freq, capacitance) +
                    calculateInductanceImpedance(freq, inductance) +
                    resistance;

        // Calculate the current flowing through the circuit
        current = 5 / impedance;

        // Calculate the voltage drop across the resistor
        voltageDrop = calculateVoltageDrop(current, resistance);

        printf("%.0f\t\t%.2f\t\t\t%.2f\n", freq, impedance, voltageDrop);
    }
    return 0;
}
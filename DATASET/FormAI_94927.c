//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define constants for the circuit
#define R1 1000 // Resistor 1 value in ohms
#define R2 2200 // Resistor 2 value in ohms
#define C1 0.00033 // Capacitor 1 value in farads
#define VIN 5 // Input voltage in volts

// Define function to calculate the output voltage
double get_output_voltage(double input_voltage, double r1, double r2, double c1) {
    double time_constant = r1 * c1;
    double output_voltage = (r2 / (r1 + r2)) * input_voltage * (1 - exp(-(1 / time_constant)));
    return output_voltage;
}

int main() {
    // Initialize variables
    double time = 0;
    double input_voltage = VIN;
    double output_voltage = 0;
    
    // Loop through time steps
    for (int t = 0; t < 100; t++) {
        // Calculate output voltage and update time
        output_voltage = get_output_voltage(input_voltage, R1, R2, C1);
        time += 0.1;
        
        // Print input and output voltage
        printf("Time: %.1f ms, Input Voltage: %0.2fV, Output Voltage: %0.2fV\n", time, input_voltage, output_voltage);
        
        // Update input voltage with sine wave
        input_voltage = VIN * sin(2 * 3.14159 * 1000 * time);
    }
    
    return 0;
}
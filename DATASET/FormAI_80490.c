//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>

// Define an element structure to hold circuit element information
struct element {
    char type;  // 'R' for resistor, 'C' for capacitor, 'L' for inductor
    double value;  // value of the element
    double current; // current through the element
    double voltage; // voltage across the element
};

// Define a function to calculate the voltage across a resistor
double calculate_resistor_voltage(double current, double resistance) {
    return current * resistance;
}

// Define a function to calculate the voltage across a capacitor
double calculate_capacitor_voltage(double current, double capacitance, double previous_voltage, double time_step) {
    return previous_voltage + (current * time_step) / capacitance;
}

// Define a function to calculate the voltage across an inductor
double calculate_inductor_voltage(double current, double inductance, double previous_voltage, double time_step) {
    return previous_voltage + (current * time_step) * inductance;
}

int main() {
    // Define the circuit elements
    struct element elements[3];
    elements[0].type = 'R';
    elements[0].value = 100;  // 100 ohm resistor
    elements[1].type = 'C';
    elements[1].value = 1e-6;  // 1 microfarad capacitor
    elements[2].type = 'L';
    elements[2].value = 1e-3;  // 1 millihenry inductor

    // Define simulation parameters
    double time_step = 1e-6;  // 1 microsecond time step
    double total_time = 1e-3;  // 1 millisecond simulation time
    int num_steps = total_time / time_step;

    // Initialize the simulation
    double voltage_source = 5;  // 5 volt DC voltage source
    double current = voltage_source / elements[0].value;  // initial current through resistor
    elements[0].current = current;
    elements[0].voltage = voltage_source;
    elements[1].current = current;
    elements[1].voltage = 0;  // initial voltage across capacitor
    elements[2].current = current;
    elements[2].voltage = 0;  // initial voltage across inductor

    // Simulate the circuit
    for (int i = 0; i < num_steps; i++) {
        // Calculate the current through the voltage source
        double current_source = current;

        // Calculate the new voltage across the resistor
        double resistor_voltage = calculate_resistor_voltage(current, elements[0].value);
        elements[0].voltage = resistor_voltage;

        // Calculate the new voltage across the capacitor
        double capacitor_voltage = calculate_capacitor_voltage(current, elements[1].value, elements[1].voltage, time_step);
        elements[1].voltage = capacitor_voltage;

        // Calculate the new voltage across the inductor
        double inductor_voltage = calculate_inductor_voltage(current, elements[2].value, elements[2].voltage, time_step);
        elements[2].voltage = inductor_voltage;

        // Calculate the new current through the resistor
        double resistor_current = (voltage_source - capacitor_voltage - inductor_voltage) / elements[0].value;
        elements[0].current = resistor_current;

        // Calculate the new current through the capacitor
        double capacitor_current = (capacitor_voltage - elements[0].voltage) / elements[1].value;
        elements[1].current = capacitor_current;

        // Calculate the new current through the inductor
        double inductor_current = (inductor_voltage - elements[0].voltage) / elements[2].value;
        elements[2].current = inductor_current;

        // Update the current and voltage for the next time step
        current = current + (resistor_current - current_source) * time_step;
        voltage_source = voltage_source + (-resistor_current * elements[0].value) * time_step;
    }

    // Print the results
    printf("Time (s)  Resistor (V)  Capacitor (V)  Inductor (V)\n");
    for (int i = 0; i < num_steps; i++) {
        double time = i * time_step;
        printf("%e  %e  %e  %e\n", time, elements[0].voltage, elements[1].voltage, elements[2].voltage);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include <stdio.h>

/* This function calculates the resistance of a node */
double calc_resistance(double voltage, double current) {
    if (current == 0) {
        return 0;
    } else {
        return voltage / current;
    }
}

/* This function calculates the voltage drop across a resistor */
double calc_voltage(double current, double resistance) {
    return current * resistance;
}

/* This function simulates a circuit by iterating over a list of components */
void simulate_circuit(int num_components, double* voltages, double* currents, double* resistances) {
    for (int i = 0; i < num_components; i++) {
        double voltage_drop = calc_voltage(currents[i], resistances[i]);
        double new_voltage = voltages[i] - voltage_drop;
        currents[i] = new_voltage / resistances[i];
        voltages[i] = new_voltage;
    }
}

int main() {
    /* Initialize the circuit */
    int num_components = 3;
    double voltages[] = {5.0, 0.0, 3.0};
    double currents[] = {0.0, 0.0, 0.0};
    double resistances[] = {100.0, 200.0, 50.0};

    /* Simulate the circuit and print the results */
    printf("Initial voltages:\n");
    for (int i = 0; i < num_components; i++) {
        printf("%f ", voltages[i]);
    }
    printf("\n");

    simulate_circuit(num_components, voltages, currents, resistances);

    printf("Final voltages:\n");
    for (int i = 0; i < num_components; i++) {
        printf("%f ", voltages[i]);
    }
    printf("\n");

    return 0;
}
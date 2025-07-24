//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include<stdio.h>

int main() {
    printf("Welcome to my Classical Circuit Simulator!\n");
    printf("Let's start building a circuit!\n");

    // Declaring and initializing variables for circuit components
    int V_source = 10;   // Voltage source, 10 volts
    int Resistor1 = 5;   // Resistor 1, 5 ohms
    int Resistor2 = 3;   // Resistor 2, 3 ohms
    int Resistor3 = 2;   // Resistor 3, 2 ohms

    // Calculating the total resistance of the circuit
    int total_resistance = Resistor1 + Resistor2 + Resistor3;

    // Calculating the total current in the circuit using Ohm's Law
    float total_current = (float)V_source / total_resistance;

    // Calculating voltage drop across each resistor using Ohm's Law
    float voltage_drop1 = Resistor1 * total_current;
    float voltage_drop2 = Resistor2 * total_current;
    float voltage_drop3 = Resistor3 * total_current;

    printf("Circuit built successfully!\n");

    // Displaying the circuit components and calculated values
    printf("\nCircuit Components:\n");
    printf("Voltage Source: %d volts\n", V_source);
    printf("Resistor 1: %d ohms\n", Resistor1);
    printf("Resistor 2: %d ohms\n", Resistor2);
    printf("Resistor 3: %d ohms\n", Resistor3);

    printf("\nCalculated Values:\n");
    printf("Total Resistance: %d ohms\n", total_resistance);
    printf("Total Current in the Circuit: %f amps\n", total_current);
    printf("Voltage Drop across Resistor 1: %f volts\n", voltage_drop1);
    printf("Voltage Drop across Resistor 2: %f volts\n", voltage_drop2);
    printf("Voltage Drop across Resistor 3: %f volts\n", voltage_drop3);

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include <stdio.h>

// Define node structure for circuit simulation
struct Node {
    int value;       // The current value of the node
    int connected;   // A flag indicating if the node is connected to a resistor
    double voltage;  // The voltage drop across the node
};

// Define a resistor structure for circuit simulation
struct Resistor {
    double resistance;  // The resistance of the resistor
    int node1;          // The node the resistor is connected to
    int node2;          // The other node the resistor is connected to
};

// Function declarations
void simulate_circuit(struct Node nodes[], struct Resistor resistors[], int num_resistors);
double calculate_voltage_drop(double current, double resistance);
double calculate_current(double voltage, double resistance);

int main() {
    // Initialize nodes and resistors for circuit simulation
    struct Node nodes[] = { {0, 0, 0.0}, {0, 0, 0.0}, {0, 0, 0.0}, {0, 0, 0.0} };
    struct Resistor resistors[] = { {10.0, 0, 1}, {5.0, 1, 2}, {7.5, 2, 3}, {12.5, 3, 0} };

    // Simulate the circuit
    simulate_circuit(nodes, resistors, 4);

    // Print the results
    for (int i = 0; i < 4; i++) {
        printf("Node %d: %dV\n", i, nodes[i].voltage);
    }

    return 0;
}

void simulate_circuit(struct Node nodes[], struct Resistor resistors[], int num_resistors) {
    // Initialize current to zero
    double current = 0.0;

    // Loop through all resistors and calculate current and voltage drop
    for (int i = 0; i < num_resistors; i++) {
        // Get the nodes the resistor is connected to
        int node1 = resistors[i].node1;
        int node2 = resistors[i].node2;

        // Calculate the current flowing through the resistor
        current = calculate_current(nodes[node1].voltage - nodes[node2].voltage, resistors[i].resistance);

        // Update the voltage drops across the nodes
        nodes[node1].voltage -= calculate_voltage_drop(current, resistors[i].resistance);
        nodes[node2].voltage += calculate_voltage_drop(current, resistors[i].resistance);

        // Update the flag indicating that the nodes are connected
        nodes[node1].connected = 1;
        nodes[node2].connected = 1;
    }

    // Loop through all nodes that are not connected to a resistor and set their voltage to zero
    for (int i = 0; i < 4; i++) {
        if (!nodes[i].connected) {
            nodes[i].voltage = 0;
        }
    }
}

double calculate_voltage_drop(double current, double resistance) {
    // Calculate the voltage drop across the resistor
    return current * resistance;
}

double calculate_current(double voltage, double resistance) {
    // Calculate the current flowing through the resistor
    return voltage / resistance;
}
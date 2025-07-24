//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>

// Define the maximum number of nodes and components in the circuit
#define MAX_NODES 100
#define MAX_COMPONENTS 100

// Enum to represent different types of circuit components
enum ComponentType {
    RESISTOR,
    INDUCTOR,
    CAPACITOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE
};

// Struct to represent a circuit component
struct Component {
    int node1; // first node connected to the component
    int node2; // second node connected to the component
    enum ComponentType type; // type of the component
    double value; // value of the component
};

// Global arrays to store the components and nodes in the circuit
struct Component components[MAX_COMPONENTS];
int nodes[MAX_NODES];

// Global variable to track the number of components in the circuit
int num_components = 0;

// Function to add a component to the circuit
void add_component(int node1, int node2, enum ComponentType type, double value) {
    components[num_components].node1 = node1;
    components[num_components].node2 = node2;
    components[num_components].type = type;
    components[num_components].value = value;
    num_components++;
}

// Function to print the circuit
void print_circuit() {
    printf("Circuit:\n");
    for (int i = 0; i < num_components; i++) {
        printf("Component %d: Node 1=%d, Node 2=%d, Type=%d, Value=%lf\n", i+1, components[i].node1, components[i].node2, components[i].type, components[i].value);
    }
}

int main() {
    // Set the nodes in the circuit
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = i+1;
    }

    // Add some components to the circuit
    add_component(1, 2, RESISTOR, 1000);
    add_component(2, 3, CAPACITOR, 0.00001);
    add_component(3, 4, INDUCTOR, 0.01);
    add_component(4, 1, VOLTAGE_SOURCE, 10);

    // Print the circuit
    print_circuit();

    return 0;
}
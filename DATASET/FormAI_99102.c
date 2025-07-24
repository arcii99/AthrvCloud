//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50

// Define circuit element types
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3
#define VOLTAGE_SOURCE 4
#define CURRENT_SOURCE 5

// Define node structure for circuit analysis
typedef struct {
    double net_current;
    double node_voltage;
    double previous_voltage;
} node;

// Define circuit element structure
typedef struct {
    int type;
    int node1;
    int node2;
    double value;
} element;

// Define global variables for circuit analysis
int num_elements = 0;
int num_nodes = 0;
node nodes[MAX_NODES];
element elements[MAX_NODES];

// Function prototypes
void add_element(int type, int node1, int node2, double value);
void initialize_nodes();
void print_node_data();
void simulate_circuit(double time, double timestep);

int main() {
    // Define circuit elements
    add_element(VOLTAGE_SOURCE, 0, 1, 5);
    add_element(RESISTOR, 1, 2, 1000);
    add_element(CAPACITOR, 2, 0, 1e-6);
    
    // Initialize nodes
    initialize_nodes();
    
    // Simulate circuit for 1ms with a timestep of 0.1ms
    simulate_circuit(1e-3, 1e-4);
    
    // Print node data after simulation
    print_node_data();
    
    return 0;
}

// Function to add an element to the circuit
void add_element(int type, int node1, int node2, double value) {
    // Check for valid node numbers
    if (node1 < 0 || node1 >= MAX_NODES || node2 < 0 || node2 >= MAX_NODES) {
        printf("Error: Invalid node numbers.\n");
        exit(1);
    }
    
    // Add element to list
    elements[num_elements].type = type;
    elements[num_elements].node1 = node1;
    elements[num_elements].node2 = node2;
    elements[num_elements].value = value;
    num_elements++;
    
    // Update number of nodes
    if (node1 > num_nodes) num_nodes = node1;
    if (node2 > num_nodes) num_nodes = node2;
}

// Function to initialize node data for circuit analysis
void initialize_nodes() {
    int i;
    for (i = 0; i <= num_nodes; i++) {
        nodes[i].net_current = 0;
        nodes[i].node_voltage = 0;
        nodes[i].previous_voltage = 0;
    }
}

// Function to print node data after simulation
void print_node_data() {
    int i;
    printf("Node\tVoltage\n");
    for (i = 0; i <= num_nodes; i++) {
        printf("%d\t%f\n", i, nodes[i].node_voltage);
    }
}

// Function to simulate circuit for a given time with a given timestep
void simulate_circuit(double time, double timestep) {
    int n = (int)(time / timestep);
    int i, j, type;
    double value, delta_v1, delta_v2, delta_i;
    for (i = 0; i < n; i++) {
        // Update node voltages
        for (j = 0; j < num_elements; j++) {
            type = elements[j].type;
            value = elements[j].value;
            switch (type) {
                case RESISTOR:
                    delta_v1 = nodes[elements[j].node1].previous_voltage - nodes[elements[j].node2].previous_voltage;
                    delta_i = delta_v1 / value;
                    nodes[elements[j].node1].net_current += delta_i;
                    nodes[elements[j].node2].net_current -= delta_i;
                    break;
                case CAPACITOR:
                    delta_v1 = nodes[elements[j].node1].previous_voltage - nodes[elements[j].node2].previous_voltage;
                    delta_i = value * (delta_v1 - nodes[elements[j].node1].net_current * timestep);
                    nodes[elements[j].node1].net_current += delta_i / timestep;
                    nodes[elements[j].node2].net_current -= delta_i / timestep;
                    break;
                case VOLTAGE_SOURCE:
                    nodes[elements[j].node1].net_current += value;
                    nodes[elements[j].node2].net_current -= value;
                    break;
                case CURRENT_SOURCE:
                    nodes[elements[j].node1].net_current -= value;
                    nodes[elements[j].node2].net_current += value;
                    break;
            }
        }
        // Calculate new node voltages
        for (j = 0; j <= num_nodes; j++) {
            nodes[j].node_voltage = nodes[j].previous_voltage + (nodes[j].net_current * timestep);
            nodes[j].previous_voltage = nodes[j].node_voltage;
            nodes[j].net_current = 0;
        }
    }
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100 // Maximum number of nodes in the circuit
#define MAX_NAME_LEN 20 // Maximum length of node names

/* Define data structure for each circuit element */
typedef struct circuit_element {
    int type;
    char name[MAX_NAME_LEN];
    int node1;
    int node2;
    double value;
} CircuitElement;

/* Define data structure for storing circuit simulation results */
typedef struct sim_data {
    double time;
    double node_voltage[MAX_NODES];
} SimData;

/* Function to simulate the circuit */
void simulate_circuit(CircuitElement circuit[], int num_elements, int num_nodes, SimData results[], int num_steps, double step_size) {
    // Initialize node voltages to zero
    double node_voltage[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        node_voltage[i] = 0.0;
    }
    
    // Iterate through each time step
    for (int step = 0; step < num_steps; step++) {
        // Record time and node voltages
        results[step].time = step * step_size;
        for (int node = 0; node < num_nodes; node++) {
            results[step].node_voltage[node] = node_voltage[node];
        }
        
        // Iterate through each circuit element
        for (int element = 0; element < num_elements; element++) {
            // Calculate current through element based on node voltages
            double current = 0.0;
            switch (circuit[element].type) {
                case 0: // Resistor
                    current = (node_voltage[circuit[element].node1] - node_voltage[circuit[element].node2]) / circuit[element].value;
                    break;
                case 1: // Capacitor
                    current = circuit[element].value * (node_voltage[circuit[element].node1] - node_voltage[circuit[element].node2]) / step_size;
                    break;
                case 2: // Inductor
                    current = (node_voltage[circuit[element].node1] - node_voltage[circuit[element].node2]) / (step_size * circuit[element].value);
                    break;
            }
            
            // Calculate change in node voltages due to element current
            double dv1 = -current;
            double dv2 = current;
            
            // Update node voltages
            node_voltage[circuit[element].node1] += dv1;
            node_voltage[circuit[element].node2] += dv2;
        }
    }
}

int main() {
    int num_elements = 5;
    int num_nodes = 3;
    CircuitElement circuit[] = {
        {0, "R1", 0, 1, 1000.0},
        {0, "R2", 1, 2, 2000.0},
        {1, "C1", 2, 0, 1e-6},
        {2, "L1", 1, 0, 10e-3},
        {0, "R3", 2, 0, 500.0}
    };
    
    int num_steps = 1000;
    double step_size = 1e-7;
    SimData results[num_steps];
    
    simulate_circuit(circuit, num_elements, num_nodes, results, num_steps, step_size);
    
    // Print simulation results
    printf("Time\tV1\tV2\tV3\n");
    for (int step = 0; step < num_steps; step++) {
        printf("%f\t%f\t%f\t%f\n", results[step].time, results[step].node_voltage[0], results[step].node_voltage[1], results[step].node_voltage[2]);
    }
    
    return 0;
}
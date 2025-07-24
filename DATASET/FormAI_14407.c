//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_ELEMENTS 2000

struct element {
    int type;
    double value;
    int node[2];
};

struct node {
    int name;
    double voltage;
};

// Global variables
struct element circuit[MAX_ELEMENTS];
struct node nodes[MAX_NODES];
int num_elements = 0;
int num_nodes = 0;

// Function prototypes
void add_resistor(int node1, int node2, double value);
void add_capacitor(int node1, int node2, double value);
void add_inductor(int node1, int node2, double value);
void add_voltage_source(int node1, int node2, double value);
void add_current_source(int node1, int node2, double value);

// Main function
int main() {
    // Add the circuit elements
    add_resistor(1, 2, 1000);
    add_capacitor(2, 3, 0.01);
    add_inductor(3, 0, 0.05);
    add_voltage_source(1, 0, 10);
    add_current_source(2, 0, 0.001);

    // Solve the circuit
    double time_step = 0.0001;
    double t_stop = 0.1;
    double t = 0.0;
    int i;

    while (t < t_stop) {
        // Calculate the currents
        double currents[num_elements];
        for (i = 0; i < num_elements; i++) {
            int node1 = circuit[i].node[0];
            int node2 = circuit[i].node[1];

            if (node1 == 0) {
                currents[i] = nodes[node2-1].voltage / circuit[i].value;
            } else if (node2 == 0) {
                currents[i] = -nodes[node1-1].voltage / circuit[i].value;
            } else {
                currents[i] = (nodes[node2-1].voltage - nodes[node1-1].voltage) / circuit[i].value;
            }
        }

        // Update the voltages
        for (i = 0; i < num_nodes; i++) {
            if (i == 0) {
                continue;
            }

            double sum = 0.0;
            int j;
            
            for (j = 0; j < num_elements; j++) {
                int node1 = circuit[j].node[0];
                int node2 = circuit[j].node[1];

                if (node1 == i) {
                    sum += currents[j];
                } else if (node2 == i) {
                    sum -= currents[j];
                }
            }

            nodes[i-1].voltage += sum * time_step;
        }

        t += time_step;
    }

    // Print the results
    for (i = 0; i < num_nodes; i++) {
        if (i == 0) {
            continue;
        }
        
        printf("Node %d: %f\n", nodes[i-1].name, nodes[i-1].voltage);
    }

    return 0;
}

void add_resistor(int node1, int node2, double value) {
    struct element e;
    e.type = 0;
    e.value = value;
    e.node[0] = node1;
    e.node[1] = node2;
    circuit[num_elements++] = e;

    if (node1 > num_nodes) {
        nodes[num_nodes++].name = node1;
    }

    if (node2 > num_nodes) {
        nodes[num_nodes++].name = node2;
    }
}

void add_capacitor(int node1, int node2, double value) {
    struct element e;
    e.type = 1;
    e.value = value;
    e.node[0] = node1;
    e.node[1] = node2;
    circuit[num_elements++] = e;

    if (node1 > num_nodes) {
        nodes[num_nodes++].name = node1;
    }

    if (node2 > num_nodes) {
        nodes[num_nodes++].name = node2;
    }
}

void add_inductor(int node1, int node2, double value) {
    struct element e;
    e.type = 2;
    e.value = value;
    e.node[0] = node1;
    e.node[1] = node2;
    circuit[num_elements++] = e;

    if (node1 > num_nodes) {
        nodes[num_nodes++].name = node1;
    }

    if (node2 > num_nodes) {
        nodes[num_nodes++].name = node2;
    }
}

void add_voltage_source(int node1, int node2, double value) {
    struct element e;
    e.type = 3;
    e.value = value;
    e.node[0] = node1;
    e.node[1] = node2;
    circuit[num_elements++] = e;

    if (node1 > num_nodes) {
        nodes[num_nodes++].name = node1;
    }

    if (node2 > num_nodes) {
        nodes[num_nodes++].name = node2;
    }
}

void add_current_source(int node1, int node2, double value) {
    struct element e;
    e.type = 4;
    e.value = value;
    e.node[0] = node1;
    e.node[1] = node2;
    circuit[num_elements++] = e;

    if (node1 > num_nodes) {
        nodes[num_nodes++].name = node1;
    }

    if (node2 > num_nodes) {
        nodes[num_nodes++].name = node2;
    }
}
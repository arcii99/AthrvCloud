//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum nodes in the circuit 
#define MAX_NODES 50

// Define the capacitor charge constant 
#define CAPACITOR_CHARGE_CONSTANT 0.00001

// Define a structure to hold the circuit node data 
typedef struct node {
    char name[10];
    double voltage;
    double current;
    char type;
    int neighbors[MAX_NODES];
    int num_neighbors;
} node_t;

// Declare global variables 
node_t circuit[MAX_NODES];
int num_nodes = 0;

// Function to add a new node to the circuit 
void add_node(char *name, char type) {
    // Check if the node already exists in the circuit 
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(name, circuit[i].name) == 0) {
            printf("Node %s already exists in the circuit.\n", name);
            return;
        }
    }

    // Add the new node to the circuit 
    strncpy(circuit[num_nodes].name, name, 10);
    circuit[num_nodes].voltage = type == 'V' ? 1.0 : 0.0;
    circuit[num_nodes].current = 0.0;
    circuit[num_nodes].type = type;
    circuit[num_nodes].num_neighbors = 0;
    num_nodes++;
}

// Function to add a connection between two nodes in the circuit 
void add_connection(char *node1, char *node2) {
    // Find the nodes in the circuit 
    int node1_idx = -1, node2_idx = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node1, circuit[i].name) == 0) {
            node1_idx = i;
        } else if (strcmp(node2, circuit[i].name) == 0) {
            node2_idx = i;
        }

        if (node1_idx != -1 && node2_idx != -1) {
            break;
        }
    }

    // Check if both nodes were found 
    if (node1_idx == -1 || node2_idx == -1) {
        printf("One or more nodes not found in circuit.\n");
        return;
    }

    // Add the connection between the nodes 
    circuit[node1_idx].neighbors[circuit[node1_idx].num_neighbors++] = node2_idx;
    circuit[node2_idx].neighbors[circuit[node2_idx].num_neighbors++] = node1_idx;
}

// Function to simulate the circuit 
void simulate_circuit(double delta_time) {
    // Iterate over all nodes in the circuit 
    for (int i = 0; i < num_nodes; i++) {
        // If the node is a voltage source, do nothing 
        if (circuit[i].type == 'V') {
            continue;
        }

        // Calculate the sum of voltages of neighboring nodes 
        double neighbor_voltages = 0.0;
        for (int j = 0; j < circuit[i].num_neighbors; j++) {
            neighbor_voltages += circuit[circuit[i].neighbors[j]].voltage;
        }

        // Calculate the current through the node 
        double new_current = (neighbor_voltages - circuit[i].voltage) / 1000.0;

        // Update the node's current 
        double delta_current = new_current - circuit[i].current;
        circuit[i].current += delta_current;

        // Update the node's voltage 
        if (circuit[i].type == 'R') {
            circuit[i].voltage += delta_time * circuit[i].current;
        } else if (circuit[i].type == 'C') {
            circuit[i].voltage += delta_time * circuit[i].current / CAPACITOR_CHARGE_CONSTANT;
        }
    }
}

int main() {
    // Add nodes to the circuit 
    add_node("node1", 'V');
    add_node("node2", 'R');
    add_node("node3", 'R');
    add_node("node4", 'C');

    // Add connections between nodes in the circuit 
    add_connection("node1", "node2");
    add_connection("node1", "node3");
    add_connection("node2", "node3");
    add_connection("node3", "node4");

    // Simulate the circuit 
    for (int i = 0; i < 10; i++) {
        simulate_circuit(0.1);
        printf("Iteration %d:\n", i + 1);
        for (int j = 0; j < num_nodes; j++) {
            printf("Node %s:\tVoltage: %lf\tCurrent: %lf\n", circuit[j].name, circuit[j].voltage, circuit[j].current);
        }
    }

    return 0;
}
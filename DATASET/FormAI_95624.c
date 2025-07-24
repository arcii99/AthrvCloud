//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>

#define NUM_NODES 5
#define MAX_EDGES 5

// Define an edge struct to store src, dest and weight of the edge
typedef struct {
    int src, dest, weight;
} edge;

// Define a node struct to hold information about the node
typedef struct {
    int id, voltage, resistance;
    edge edges[MAX_EDGES];
    int num_edges;
} node;

node nodes[NUM_NODES]; // Array of nodes

// Function to add an edge to a node
void add_edge(int node_id, int dest, int weight) {
    int num_edges = nodes[node_id].num_edges;
    nodes[node_id].edges[num_edges].src = node_id;
    nodes[node_id].edges[num_edges].dest = dest;
    nodes[node_id].edges[num_edges].weight = weight;
    nodes[node_id].num_edges++;
}

// Function to simulate the circuit
void simulate_circuit() {
    // Initialize the voltage of all nodes to 0
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i].voltage = 0;
    }
    
    // Loop through each node and calculate the voltage
    for (int i = 0; i < NUM_NODES; i++) {
        int num_edges = nodes[i].num_edges;
        int total_weight = 0;
        
        // Calculate the total weight of all connected edges
        for (int j = 0; j < num_edges; j++) {
            int dest = nodes[i].edges[j].dest;
            total_weight += nodes[i].edges[j].weight;
        }
        
        // Calculate the voltage using Ohm's law
        nodes[i].voltage = total_weight * nodes[i].resistance;
    }
}

// Function to print the current voltage of all nodes
void print_voltages() {
    printf("Node Voltages:\n");
    for (int i = 0; i < NUM_NODES; i++) {
        printf("Node %d: %dV\n", i, nodes[i].voltage);
    }
}

int main() {
    // Initialize the nodes
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i].id = i;
        nodes[i].voltage = 0;
        nodes[i].resistance = 1;
        nodes[i].num_edges = 0;
    }
    
    // Add edges to the nodes
    add_edge(0, 1, 2);
    add_edge(1, 2, 3);
    add_edge(2, 3, 4);
    add_edge(3, 4, 5);
    
    // Simulate the circuit
    simulate_circuit();
    
    // Print the voltages of all nodes
    print_voltages();
    
    return 0;
}
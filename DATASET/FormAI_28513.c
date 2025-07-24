//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_EDGES 50

// Node data structure
typedef struct {
    int id;
    double voltage;
    double current;
} Node;

// Edge (Component) data structure
typedef struct {
    int id;
    int from_node;
    int to_node;
    double resistance;
} Edge;

// Circuit data structure
typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Circuit;

// Recursive function for calculating current
// through a circuit node
double calculate_current(Circuit c, int node_id) {
    double total_current = 0.0;
    
    for (int i = 0; i < c.num_edges; i++) {
        Edge e = c.edges[i];
        
        if (e.from_node == node_id) {
            double current = (c.nodes[e.from_node].voltage - c.nodes[e.to_node].voltage) / e.resistance;
            c.nodes[e.to_node].current = current;
            total_current += current;
            
            // Recursively calculate current for downstream nodes
            total_current += calculate_current(c, e.to_node);
        }
    }
    
    return total_current;
}

int main() {
    // Create circuit
    Circuit circuit;
    circuit.num_nodes = 3;
    circuit.num_edges = 2;
    
    Node node1 = { 0, 5.0, 0.0 };
    Node node2 = { 1, 0.0, 0.0 };
    Node node3 = { 2, 0.0, 0.0 };
    
    Edge edge1 = { 0, 0, 1, 1.0 };
    Edge edge2 = { 1, 1, 2, 2.0 };
    
    circuit.nodes[0] = node1;
    circuit.nodes[1] = node2;
    circuit.nodes[2] = node3;
    
    circuit.edges[0] = edge1;
    circuit.edges[1] = edge2;
    
    // Calculate current through each node
    for (int i = 0; i < circuit.num_nodes; i++) {
        calculate_current(circuit, i);
    }
    
    // Print results
    for (int i = 0; i < circuit.num_nodes; i++) {
        printf("Node %d:\n", i);
        printf("\tVoltage: %.2f V\n", circuit.nodes[i].voltage);
        printf("\tCurrent: %.2f A\n", circuit.nodes[i].current);
    }
    
    return 0;
}
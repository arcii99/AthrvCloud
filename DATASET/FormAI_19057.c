//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    int from;
    int to;
    double current;
} Edge;

void simulate_circuit(int num_nodes, int num_edges, Edge edges[]) {
    double node_values[MAX_NODES] = {0.0};
    int i, j;

    // initialize node voltages
    node_values[0] = 10.0;

    // loop through all edges and calculate current
    for (i=0; i<num_edges; i++) {
        Edge edge = edges[i];
        int from = edge.from;
        int to = edge.to;
        double voltage = node_values[from] - node_values[to];
        double resistance = 1.0;
        double current = voltage / resistance;
        edge.current = current;
        node_values[to] += current;
        node_values[from] -= current;
    }

    // print out edge current values
    printf("Edge Currents:\n");
    for (i=0; i<num_edges; i++) {
        Edge edge = edges[i];
        printf("Edge %d-%d: %f\n", edge.from, edge.to, edge.current);
    }

    // print out node voltages
    printf("Node Voltages: ");
    for (i=0; i<num_nodes; i++) {
        printf("%f ", node_values[i]);
    }
}

int main(int argc, char *argv[]) {
    int num_nodes = 5;
    int num_edges = 4;
    Edge edges[MAX_EDGES] = {{0, 1, 0.0}, {1, 2, 0.0}, {2, 3, 0.0}, {3, 4, 0.0}};

    printf("Simulating Circuit with %d Nodes and %d Edges\n", num_nodes, num_edges);
    simulate_circuit(num_nodes, num_edges, edges);

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

/* Circuit Node Structure */
typedef struct node {
    char name[10];
    double voltage;
    double current;
} Node;

/* Circuit Circuit Structure */
typedef struct circuit {
    int num_nodes;
    Node nodes[MAX_NODES];
} Circuit;

/* Function to calculate the voltage and current
 * for each node in the circuit */
void simulate_circuit(Circuit circuit) {
    for (int i = 0; i < circuit.num_nodes; i++) {
        printf("Node %s:\n", circuit.nodes[i].name);
        printf("  Voltage: %.2lfV\n", circuit.nodes[i].voltage);
        printf("  Current: %.2lfA\n", circuit.nodes[i].current);
    }
}

int main() {
    /* Create Example Circuit */
    Circuit circuit = {3, {
        {"Node 1", 5.0, 0.0},
        {"Node 2", 10.0, 0.0},
        {"Node 3", 15.0, 0.0},
    }};
    
    /* Simulate Circuit */
    simulate_circuit(circuit);
    
    return 0;
}
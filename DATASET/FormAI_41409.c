//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_BRANCHES 20

typedef struct {
    double value; // Resistance or Conductance value
    int nodeI; // Pointer to node i
    int nodeJ; // Pointer to node j
} Branch;

typedef struct {
    double voltage; // Voltage between nodes
    double conductance; // Conductance between nodes
} Node;

int numNodes, numBranches;
Node nodes[MAX_NODES];
Branch branches[MAX_BRANCHES];

void solveCircuit() {
    double Y[MAX_NODES][MAX_NODES], V[MAX_NODES];

    // Initialize matrices to zero
    for(int i = 0; i < MAX_NODES; i++) {
        V[i] = 0;
        for(int j = 0; j < MAX_NODES; j++) {
            Y[i][j] = 0;
        }
    }

    // Populate Y matrix with conductances
    for(int i = 0; i < numBranches; i++) {
        Branch b = branches[i];
        int nodeI = b.nodeI;
        int nodeJ = b.nodeJ;
        double value = b.value;

        if(nodeI >= 0) {
            Y[nodeI][nodeI] += value;
        }
        if(nodeJ >= 0) {
            Y[nodeJ][nodeJ] += value;
        }
        if(nodeI >= 0 && nodeJ >= 0) {
            Y[nodeI][nodeJ] -= value;
            Y[nodeJ][nodeI] -= value;
        }
    }

    // Solve for node voltages
    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            V[i] += nodes[j].voltage * Y[i][j];
        }
    }

    // Print node voltages
    printf("Node Voltages:\n");
    for(int i = 0; i < numNodes; i++) {
        printf("Node %d: %lfV\n", i+1, V[i]);
    }
}

int main() {
    // Add nodes
    numNodes = 3;
    nodes[0].voltage = 5;
    nodes[1].voltage = 0;
    nodes[2].voltage = 0;

    // Add branches
    numBranches = 3;

    branches[0].nodeI = 0;
    branches[0].nodeJ = 1;
    branches[0].value = 1000;

    branches[1].nodeI = 0;
    branches[1].nodeJ = 2;
    branches[1].value = 500;

    branches[2].nodeI = 1;
    branches[2].nodeJ = 2;
    branches[2].value = 500;

    // Solve circuit
    solveCircuit();

    return 0;
}
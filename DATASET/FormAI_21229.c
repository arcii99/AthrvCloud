//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_TRANSISTORS 10000

typedef struct {
    int node1;
    int node2;
    double value;
} Resistor;

typedef struct {
    int base;
    int emitter;
    int collector;
    double gain;
} Transistor;

Resistor resistors[MAX_TRANSISTORS];
Transistor transistors[MAX_TRANSISTORS];

double nodes[MAX_NODES];
bool grounded[MAX_NODES];
int nodeCount = 0;
int resistorCount = 0;
int transistorCount = 0;

void createNode() {
    nodes[nodeCount] = 0;
    grounded[nodeCount] = false;
    nodeCount++;
}

void groundNode(int node) {
    grounded[node] = true;
}

void addResistor(int node1, int node2, double resistance) {
    resistors[resistorCount].node1 = node1;
    resistors[resistorCount].node2 = node2;
    resistors[resistorCount].value = 1 / resistance;
    resistorCount++;
}

void addTransistor(int base, int emitter, int collector, double gain) {
    transistors[transistorCount].base = base;
    transistors[transistorCount].emitter = emitter;
    transistors[transistorCount].collector = collector;
    transistors[transistorCount].gain = gain;
    transistorCount++;
}

void solveCircuit() {
    // build the conductance matrix
    double conductance[nodeCount][nodeCount];
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            conductance[i][j] = 0;
        }
    }
    for (int i = 0; i < resistorCount; i++) {
        int node1 = resistors[i].node1;
        int node2 = resistors[i].node2;
        double value = resistors[i].value;
        if (!grounded[node1]) {
            conductance[node1][node1] += value;
        }
        if (!grounded[node2]) {
            conductance[node2][node2] += value;
        }
        if (!grounded[node1] && !grounded[node2]) {
            conductance[node1][node2] -= value;
            conductance[node2][node1] -= value;
        }
    }
    for (int i = 0; i < transistorCount; i++) {
        int base = transistors[i].base;
        int emitter = transistors[i].emitter;
        int collector = transistors[i].collector;
        double gain = transistors[i].gain;
        if (!grounded[base] && !grounded[emitter]) {
            conductance[base][emitter] -= gain;
            conductance[emitter][base] -= gain;
        }
        if (!grounded[emitter] && !grounded[collector]) {
            conductance[emitter][collector] -= gain;
            conductance[collector][emitter] -= gain;
        }
        if (!grounded[base] && !grounded[collector]) {
            conductance[base][collector] += gain;
            conductance[collector][base] += gain;
        }
    }
    // solve for node potentials
    for (int i = 0; i < nodeCount; i++) {
        int p;
        for (p = i; p < nodeCount; p++) {
            if (fabs(conductance[p][i]) > 1e-8) {
                break;
            }
        }
        if (p == nodeCount) {
            printf("Error: singular conductance matrix\n");
            exit(1);
        }
        if (p != i) {
            for (int j = 0; j < nodeCount; j++) {
                double tmp = conductance[i][j];
                conductance[i][j] = conductance[p][j];
                conductance[p][j] = tmp;
            }
            double tmp = nodes[i];
            nodes[i] = nodes[p];
            nodes[p] = tmp;
        }
        for (int j = i + 1; j < nodeCount; j++) {
            double factor = conductance[j][i] / conductance[i][i];
            for (int k = i; k < nodeCount; k++) {
                conductance[j][k] -= factor * conductance[i][k];
            }
            nodes[j] -= factor * nodes[i];
        }
    }
    for (int i = nodeCount - 1; i >= 0; i--) {
        for (int j = i + 1; j < nodeCount; j++) {
            nodes[i] -= conductance[i][j] * nodes[j];
            conductance[i][j] = 0;
        }
        nodes[i] /= conductance[i][i];
        conductance[i][i] = 1;
    }
}

int main() {
    createNode();
    createNode();
    createNode();
    createNode();
    addResistor(0, 1, 1000);
    addResistor(1, 2, 1000);
    addResistor(2, 0, 1000);
    addTransistor(0, 1, 2, 100);
    solveCircuit();
    printf("Node Potentials:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("Node %d: %f\n", i, nodes[i]);
    }
    return 0;
}
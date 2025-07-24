//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_RESISTORS 20

/* Define the Circuit Struct */
typedef struct Resistor_s {
    double resistance;
    int node1;
    int node2;
} Resistor;

typedef struct Circuit_s {
    int numNodes;
    int numResistors;
    Resistor resistors[MAX_RESISTORS];
} Circuit;

/* Function to initialize a circuit */
void initializeCircuit(Circuit* circuit, int numNodes) {
    circuit->numNodes = numNodes;
    circuit->numResistors = 0;
    for(int i = 0; i < MAX_RESISTORS; i++) {
        circuit->resistors[i].resistance = 0;
        circuit->resistors[i].node1 = 0;
        circuit->resistors[i].node2 = 0;
    }
}

/* Add resistor to the circuit */
int addResistor(Circuit* circuit, double resistance, int node1, int node2) {
    if(circuit->numResistors >= MAX_RESISTORS) {
        return -1; // Too many resistors
    }
    if(resistance <= 0) {
        return -2; // Invalid resistance value
    }
    if(node1 < 0 || node1 >= circuit->numNodes || node2 < 0 || node2 >= circuit->numNodes) {
        return -3; // Invalid node values
    }
    if(node1 == node2) {
        return -4; // Cannot connect to same node
    }
    /* Check if resistor already exists */
    for(int i = 0; i < circuit->numResistors; i++) {
        if((circuit->resistors[i].node1 == node1 && circuit->resistors[i].node2 == node2) ||
            (circuit->resistors[i].node1 == node2 && circuit->resistors[i].node2 == node1)) {
                return -5; // Resistor already exists
        }
    }
    /* Add resistor to circuit */
    circuit->resistors[circuit->numResistors].resistance = resistance;
    circuit->resistors[circuit->numResistors].node1 = node1;
    circuit->resistors[circuit->numResistors].node2 = node2;
    circuit->numResistors++;
    return 0;
}

/* Calculate the resistance between two nodes */
double calculateResistance(Circuit* circuit, int node1, int node2) {
    /* Initialize the node matrix */
    double nodes[MAX_NODES][MAX_NODES];
    for(int i = 0; i < MAX_NODES; i++) {
        for(int j = 0; j < MAX_NODES; j++) {
            nodes[i][j] = 0;
        }
    }
    /* Fill in the node matrix */
    for(int i = 0; i < circuit->numResistors; i++) {
        int n1 = circuit->resistors[i].node1;
        int n2 = circuit->resistors[i].node2;
        double r = circuit->resistors[i].resistance;
        nodes[n1][n1] += (1/r);
        nodes[n2][n2] += (1/r);
        nodes[n1][n2] -= (1/r);
        nodes[n2][n1] -= (1/r);
    }
    /* Calculate resistance between nodes */
    int n = circuit->numNodes;
    double denominator = nodes[node1][node1]*nodes[node2][node2] - nodes[node1][node2]*nodes[node2][node1];
    if(denominator == 0) {
        return INFINITY; // No connection between nodes
    }
    double resistance = nodes[node1][node1]*nodes[node2][node2]/denominator;
    return resistance;
}

/* Main function */
int main() {
    Circuit circuit;
    int numNodes = 4;
    initializeCircuit(&circuit, numNodes);
    addResistor(&circuit, 2.0, 0, 1);
    addResistor(&circuit, 3.0, 1, 2);
    addResistor(&circuit, 4.0, 2, 3);
    double resistance = calculateResistance(&circuit, 0, 3);
    printf("Total Resistance between nodes 0 and 3 is %.2f Ohms\n", resistance);
    return 0;
}
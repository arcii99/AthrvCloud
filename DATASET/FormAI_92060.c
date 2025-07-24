//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define MAX_NODES 1000

/* Struct to hold information for every element in the circuit */
typedef struct Element {
    int node1;
    int node2;
    double complex value;
} Element;

/* Struct to hold the state of the circuit at any given time */
typedef struct Circuit {
    int numNodes;
    int numElements;
    Element elements[MAX_NODES];
    double complex voltages[MAX_NODES];
    double complex currents[MAX_NODES];
} Circuit;

void simulate(Circuit circuit, double complex *solutions) {
    /* Initialize the solutions vector to all zeroes */
    for (int i = 0; i < circuit.numNodes; i++) {
        solutions[i] = 0.0 + 0.0*I;
    }

    /* Solve the circuit using nodal analysis */
    for (int i = 0; i < circuit.numElements; i++) {
        Element elem = circuit.elements[i];
        if (elem.node1 != 0) {
            solutions[elem.node1 - 1] += circuit.voltages[elem.node1 - 1] * elem.value;
        }
        if (elem.node2 != 0) {
            solutions[elem.node2 - 1] -= circuit.voltages[elem.node2 - 1] * elem.value;
        }
    }

    /* Calculate the currents flowing through each element */
    for (int i = 0; i < circuit.numElements; i++) {
        Element elem = circuit.elements[i];
        double complex node1 = solutions[elem.node1 - 1];
        double complex node2 = solutions[elem.node2 - 1];
        circuit.currents[i] = (node1 - node2) * elem.value;
    }
}

int main() {
    /* Define the circuit */
    Circuit circuit = {
        .numNodes = 4,
        .numElements = 3,
        .elements = {
            {1, 2, 0.1 + 0*I},
            {2, 3, 0.2 + 0*I},
            {3, 4, 0.3 + 0*I},
        },
        .voltages = {0 + 0*I, 5 + 0*I, 0 + 0*I, 0 + 0*I},
        .currents = {0 + 0*I, 0 + 0*I, 0 + 0*I},
    };

    /* Simulate the circuit */
    double complex solutions[MAX_NODES];
    simulate(circuit, solutions);

    /* Print the results */
    printf("Node Voltages:\n");
    for (int i = 0; i < circuit.numNodes; i++) {
        printf("Node %d: %.2f + %.2fi\n", i+1, creal(solutions[i]), cimag(solutions[i]));
    }

    printf("\nElement Currents:\n");
    for (int i = 0; i < circuit.numElements; i++) {
        printf("Element %d: %.2f + %.2fi\n", i+1, creal(circuit.currents[i]), cimag(circuit.currents[i]));
    }

    return 0;
}
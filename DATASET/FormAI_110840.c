//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100 // Maximum number of nodes in a circuit
#define MAX_NAME 20 // Maximum length of component name

typedef struct Component {
    int node1; // first node
    int node2; // second node
    double value; // component value
    char name[MAX_NAME]; // component name
    char type; // component type (R, C, L)
} Component;

Component circuit[MAX_NODES];
int numComponents = 0;

double nodes[MAX_NODES]; // the nodes of the circuit
int numNodes = 0;

// function to add a component to the circuit
void add_component(int node1, int node2, double value, char* name, char type) {
    circuit[numComponents].node1 = node1;
    circuit[numComponents].node2 = node2;
    circuit[numComponents].value = value;
    circuit[numComponents].type = type;
    strcpy(circuit[numComponents].name, name);
    numComponents++;
}

// function to calculate the conductance of a resistor
double conductance(double value) {
    return 1.0 / value;
}

// function to solve the circuit using nodal analysis
void solve_circuit() {
    double A[MAX_NODES][MAX_NODES]; // Matrix A
    double b[MAX_NODES]; // Matrix b
    int i, j, k;

    // initialize matrices
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            A[i][j] = 0;
        }
        b[i] = 0;
    }

    // fill in matrix A and b
    for (i = 0; i < numComponents; i++) {
        if (circuit[i].type == 'R') {
            double G = conductance(circuit[i].value);
            A[circuit[i].node1][circuit[i].node1] += G;
            A[circuit[i].node1][circuit[i].node2] -= G;
            A[circuit[i].node2][circuit[i].node1] -= G;
            A[circuit[i].node2][circuit[i].node2] += G;
        }
        else if (circuit[i].type == 'C') {
            double C = circuit[i].value;
            A[circuit[i].node1][circuit[i].node1] += C;
            A[circuit[i].node1][circuit[i].node2] -= C;
            A[circuit[i].node2][circuit[i].node1] -= C;
            A[circuit[i].node2][circuit[i].node2] += C;
            b[circuit[i].node1] -= C * nodes[circuit[i].node2];
            b[circuit[i].node2] += C * nodes[circuit[i].node1];
        }
    }

    // solve for the voltages at each node
    for (i = 0; i < numNodes; i++) {
        for (j = i + 1; j < numNodes; j++) {
            double factor = A[j][i] / A[i][i];
            for (k = i; k < numNodes; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    for (i = numNodes - 1; i >= 0; i--) {
        nodes[i] = b[i] / A[i][i];
        for (j = i - 1; j >= 0; j--) {
            b[j] -= A[j][i] * nodes[i];
        }
    }
}

int main() {
    // add components to circuit
    add_component(0, 1, 1000, "R1", 'R');
    add_component(1, 2, 2000, "R2", 'R');
    add_component(0, 2, 0.000001, "C1", 'C');

    // find number of nodes in circuit
    for (int i = 0; i < numComponents; i++) {
        if (circuit[i].node1 > numNodes) {
            numNodes = circuit[i].node1;
        }
        if (circuit[i].node2 > numNodes) {
            numNodes = circuit[i].node2;
        }
    }
    numNodes++; // account for ground node

    // initialize nodes to initial guess
    for (int i = 0; i < numNodes; i++) {
        nodes[i] = 0;
    }

    // solve circuit
    solve_circuit();

    // print results
    printf("Node voltages:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %lfV\n", i, nodes[i]);
    }

    return 0;
}
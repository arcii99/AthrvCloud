//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: brave
#include <stdio.h>
#include <math.h>

/* brave C Classical Circuit Simulator example program */

#define MAX_NODES 20
#define MAX_ELEMENTS 20

/* model for each circuit element */
typedef struct {
    char type;
    double value;
    int node1, node2;
} element;

double conductance[MAX_NODES][MAX_NODES];
double nodeVoltage[MAX_NODES];
element circuit[MAX_ELEMENTS];
int numElements = 0;
int numNodes = 0;

/* function to add a circuit element */
void addElement(char type, double value, int node1, int node2) {
    circuit[numElements].type = type;
    circuit[numElements].value = value;
    circuit[numElements].node1 = node1;
    circuit[numElements].node2 = node2;
    numElements++;
}

/* function to solve the circuit */
void solve() {
    int i, j, k;

    /* initialize conductance matrix to zero */
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            conductance[i][j] = 0.0;
        }
    }

    /* loop through all elements to build the conductance matrix */
    for (i = 0; i < numElements; i++) {
        /* add conductance of resistor or capacitor to appropriate locations */
        if (circuit[i].type == 'R' || circuit[i].type == 'C') {
            conductance[circuit[i].node1][circuit[i].node1] += 1.0/circuit[i].value;
            conductance[circuit[i].node2][circuit[i].node2] += 1.0/circuit[i].value;
            conductance[circuit[i].node1][circuit[i].node2] -= 1.0/circuit[i].value;
            conductance[circuit[i].node2][circuit[i].node1] -= 1.0/circuit[i].value;
        }
        /* add conductance of voltage source to appropriate locations */
        else if (circuit[i].type == 'V') {
            conductance[circuit[i].node1][numNodes] += 1.0;
            conductance[circuit[i].node2][numNodes] -= 1.0;
            conductance[numNodes][circuit[i].node1] -= 1.0;
            conductance[numNodes][circuit[i].node2] += 1.0;
            nodeVoltage[numNodes] = circuit[i].value;
            numNodes++;
        }
        /* add conductance of current source to appropriate locations */
        else if (circuit[i].type == 'I') {
            conductance[circuit[i].node1][circuit[i].node1] += circuit[i].value;
            conductance[circuit[i].node2][circuit[i].node2] += circuit[i].value;
            conductance[circuit[i].node1][circuit[i].node2] -= circuit[i].value;
            conductance[circuit[i].node2][circuit[i].node1] -= circuit[i].value;
        }
    }

    /* solve using gaussian elimination */
    for (k = 0; k < numNodes; k++) {
        for (i = k; i < numNodes; i++) {
            if (fabs(conductance[i][k]) > fabs(conductance[k][k])) {
                for (j = 0; j <= numNodes; j++) {
                    double temp = conductance[k][j];
                    conductance[k][j] = conductance[i][j];
                    conductance[i][j] = temp;
                }
            }
        }
        for (i = k+1; i < numNodes; i++) {
            double factor = conductance[i][k]/conductance[k][k];
            for (j = k; j <= numNodes; j++) {
                conductance[i][j] -= factor * conductance[k][j];
            }
        }
    }
    for (i = numNodes-1; i >= 0; i--) {
        double sum = 0.0;
        for (j = i+1; j < numNodes; j++) {
            sum += conductance[i][j] * nodeVoltage[j];
        }
        nodeVoltage[i] = (conductance[i][numNodes] - sum) / conductance[i][i];
    }
}

/* main function */
int main() {
    /* set up the circuit */
    addElement('R', 1000.0, 0, 1);
    addElement('C', 1.0/(2*M_PI*1000.0), 1, 2);
    addElement('V', 10.0, 0, 2);

    /* solve the circuit */
    solve();

    /* print the results */
    printf("Node voltages:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %lf\n", i, nodeVoltage[i]);
    }

    return 0;
}
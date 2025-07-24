//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE_NUMBER 100
#define MAX_RESISTOR_NUMBER 100
#define MAX_SOURCE_NUMBER 5

// Structs to represent circuit components
typedef struct {
    int node1;
    int node2;
    double value;
} Resistor;

typedef struct {
    int node1;
    int node2;
    double value;
} VoltageSource;

typedef struct {
    int node1;
    int node2;
    double value;
} CurrentSource;

// Global variables to hold circuit parameters
Resistor resistors[MAX_RESISTOR_NUMBER];
VoltageSource vSources[MAX_SOURCE_NUMBER];
CurrentSource iSources[MAX_SOURCE_NUMBER];
int resistorCount = 0;
int vSourceCount = 0;
int iSourceCount = 0;

// Global variables to hold simulation results
double nodeVoltages[MAX_NODE_NUMBER];

// Function to add a resistor to the circuit
void addResistor(int node1, int node2, double value) {
    resistors[resistorCount].node1 = node1;
    resistors[resistorCount].node2 = node2;
    resistors[resistorCount].value = value;
    resistorCount++;
}

// Function to add a voltage source to the circuit
void addVoltageSource(int node1, int node2, double value) {
    vSources[vSourceCount].node1 = node1;
    vSources[vSourceCount].node2 = node2;
    vSources[vSourceCount].value = value;
    vSourceCount++;
}

// Function to add a current source to the circuit
void addCurrentSource(int node1, int node2, double value) {
    iSources[iSourceCount].node1 = node1;
    iSources[iSourceCount].node2 = node2;
    iSources[iSourceCount].value = value;
    iSourceCount++;
}

// Function to solve the circuit
void solve() {
    int i, j, k;
    double conductanceMatrix[MAX_NODE_NUMBER][MAX_NODE_NUMBER];
    double rhs[MAX_NODE_NUMBER];

    // Initialize matrices to zero
    for (i = 0; i < MAX_NODE_NUMBER; i++) {
        for (j = 0; j < MAX_NODE_NUMBER; j++) {
            conductanceMatrix[i][j] = 0.0;
        }
        rhs[i] = 0.0;
        nodeVoltages[i] = 0.0;
    }

    // Calculate conductance matrix
    for (i = 0; i < resistorCount; i++) {
        int node1 = resistors[i].node1;
        int node2 = resistors[i].node2;
        double value = resistors[i].value;
        conductanceMatrix[node1][node1] += 1.0 / value;
        conductanceMatrix[node2][node2] += 1.0 / value;
        conductanceMatrix[node1][node2] -= 1.0 / value;
        conductanceMatrix[node2][node1] -= 1.0 / value;
    }

    // Add voltage sources to conductance matrix
    for (i = 0; i < vSourceCount; i++) {
        int node1 = vSources[i].node1;
        int node2 = vSources[i].node2;
        double value = vSources[i].value;
        conductanceMatrix[node1][node2] -= 1.0;
        conductanceMatrix[node2][node1] += 1.0;
        rhs[node1] -= value;
        rhs[node2] += value;
    }

    // Add current sources to rhs vector
    for (i = 0; i < iSourceCount; i++) {
        int node1 = iSources[i].node1;
        int node2 = iSources[i].node2;
        double value = iSources[i].value;
        rhs[node1] += value;
        rhs[node2] -= value;
    }

    // Solve for node voltages
    for (k = 0; k < MAX_NODE_NUMBER; k++) {
        int maxRowIndex = k;
        double maxRowValue = conductanceMatrix[k][k];
        for (i = k+1; i < MAX_NODE_NUMBER; i++) {
            if (fabs(conductanceMatrix[i][k]) > fabs(maxRowValue)) {
                maxRowIndex = i;
                maxRowValue = conductanceMatrix[i][k];
            }
        }
        if (maxRowIndex != k) {
            // Swap rows
            for (j = 0; j < MAX_NODE_NUMBER; j++) {
                double temp = conductanceMatrix[k][j];
                conductanceMatrix[k][j] = conductanceMatrix[maxRowIndex][j];
                conductanceMatrix[maxRowIndex][j] = temp;
            }
            double temp = rhs[k];
            rhs[k] = rhs[maxRowIndex];
            rhs[maxRowIndex] = temp;
        }
        double pivotValue = conductanceMatrix[k][k];
        for (j = k; j < MAX_NODE_NUMBER; j++) {
            conductanceMatrix[k][j] /= pivotValue;
        }
        rhs[k] /= pivotValue;
        for (i = k+1; i < MAX_NODE_NUMBER; i++) {
            double multiplier = conductanceMatrix[i][k];
            for (j = k; j < MAX_NODE_NUMBER; j++) {
                conductanceMatrix[i][j] -= multiplier * conductanceMatrix[k][j];
            }
            rhs[i] -= multiplier * rhs[k];
        }
    }
    for (k = MAX_NODE_NUMBER-1; k >= 0; k--) {
        nodeVoltages[k] = rhs[k];
        for (i = 0; i < k; i++) {
            rhs[i] -= conductanceMatrix[i][k] * nodeVoltages[k];
            conductanceMatrix[i][k] = 0.0;
        }
    }
}

int main() {
    addResistor(0, 1, 1000.0);
    addResistor(1, 2, 1000.0);
    addResistor(2, 3, 1000.0);
    addVoltageSource(0, 3, -1.0);
    solve();
    printf("Node voltages:\n");
    printf("Node 0: %f\n", nodeVoltages[0]);
    printf("Node 1: %f\n", nodeVoltages[1]);
    printf("Node 2: %f\n", nodeVoltages[2]);
    printf("Node 3: %f\n", nodeVoltages[3]);
    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MIN 1e-9

int numberOfNodes, numberOfElements;
double g[MAX_NODES + 1][MAX_NODES + 1];
double b[MAX_NODES + 1][MAX_NODES + 1];
double u[MAX_NODES +1];

void addElement(int i, int j, double value) {
    if (i != 0) {
        g[i][i] += value;
    }
    if (j != 0) {
        g[j][j] += value;
    }
    if (i != 0 && j != 0) {
        g[i][j] -= value;
        g[j][i] -= value;
    }
}

void addResistor(int i, int j, double resistance) {
    double value = 1/resistance;
    addElement(i, j, value);
}

void addCapacitor(int i, int j, double capacitance, double timeStep) {
    double value = 2*capacitance/timeStep;
    addElement(i, i, value);
    addElement(j, j, value);
    addElement(i, j, -value);
    addElement(j, i, -value);
}

void addVoltageSource(int i, int j, double voltage) {
    if (i != 0) {
        b[i][numberOfElements + 1] += voltage;
    }
    if (j != 0) {
        b[j][numberOfElements + 1] -= voltage;
    }
    numberOfElements++;
}

void addGroundNode(int i) {
    g[i][i] = 1;
}

void voltageSolver() {
    for (int k = 1; k <= numberOfNodes; k++) {
        for (int i = 1; i <= numberOfNodes; i++) {
            if (i != k) {
                double factor = g[i][k]/g[k][k];
                for (int j = k+1; j <= numberOfNodes+1; j++) {
                    g[i][j] -= factor * g[k][j];
                }
                b[i][numberOfNodes+1] -= factor * b[k][numberOfNodes+1];
            }
        }
    }

    for (int i = numberOfNodes; i >= 1; i--) {
        u[i] = b[i][numberOfNodes+1]/g[i][i];
        for (int j = i-1; j >= 1; j--) {
            b[j][numberOfNodes+1] -= g[j][i] * u[i];
        }
    }
}

int main() {
    numberOfNodes = 4;

    addResistor(1, 2, 2200);
    addResistor(2, 3, 1000);
    addResistor(3, 4, 3300);
    addVoltageSource(1, 0, 12);
    addGroundNode(4);

    voltageSolver();

    printf("Voltage at node 1: %.2f\n", u[1]);
    printf("Voltage at node 2: %.2f\n", u[2]);
    printf("Voltage at node 3: %.2f\n", u[3]);
    printf("Voltage at node 4: %.2f\n", u[4]);

    return 0;
}
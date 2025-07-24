//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <math.h>

#define MAX_NODES 20
#define MAX_RESISTORS 50

double resistance[MAX_RESISTORS];
int node1[MAX_RESISTORS], node2[MAX_RESISTORS];
int numResistors = 0;
int numNodes = 0;

void insertResistor(int n1, int n2, double r) {
    resistance[numResistors] = r;
    node1[numResistors] = n1;
    node2[numResistors] = n2;
    numResistors++;
}

double getNodeVoltage(int node) {
    int i;
    double resistanceSum = 0.0, voltageSum = 0.0;

    for (i = 0; i < numResistors; i++) {
        if (node1[i] == node) {
            resistanceSum += resistance[i];
            voltageSum += getNodeVoltage(node2[i]);
        } else if (node2[i] == node) {
            resistanceSum += resistance[i];
            voltageSum += getNodeVoltage(node1[i]);
        }
    }

    return voltageSum / resistanceSum;
}

int main() {
    insertResistor(1, 2, 1000.0);
    insertResistor(2, 3, 2000.0);
    insertResistor(3, 1, 500.0);

    printf("Node 1: %.2fV\n", getNodeVoltage(1));
    printf("Node 2: %.2fV\n", getNodeVoltage(2));
    printf("Node 3: %.2fV\n", getNodeVoltage(3));

    return 0;
}
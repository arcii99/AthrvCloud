//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_DATA 10000
#define PI 3.14159265358979323846

typedef struct {
    int node1;
    int node2;
    double value;
} Component;

int numNodes, numComponents;
Component components[MAX_DATA];

double complexMatrix[MAX_NODES][MAX_NODES];
double complexVector[MAX_NODES];

void addComponent(int node1, int node2, double value) {
    Component component = {node1, node2, value};
    components[numComponents] = component;
    numComponents++;
}

void initializeMatrix() {
    for(int i = 0; i < numNodes; i++) {
        for(int j = 0; j < numNodes; j++) {
            complexMatrix[i][j] = 0;
        }
    }
}

void fillMatrix() {
    for(int i = 0; i < numComponents; i++) {
        int node1 = components[i].node1;
        int node2 = components[i].node2;
        double value = components[i].value;

        if(node1 != 0) {
            complexMatrix[node1][node1] += 1/value;
            complexMatrix[node2][node2] += 1/value;
            complexMatrix[node1][node2] -= 1/value;
            complexMatrix[node2][node1] -= 1/value;
        }
    }
}

void solveMatrix() {
    for(int i = 0; i < numNodes; i++) {
        complexVector[i] = 0;
    }

    complexMatrix[0][0] = 1;
    for(int i = 1; i < numNodes; i++) {
        complexMatrix[i][i] += 1;
    }

    for(int i = 0; i < numNodes; i++) {
        for(int j = i + 1; j < numNodes; j++) {
            double factor = complexMatrix[j][i] / complexMatrix[i][i];

            for(int k = i; k < numNodes; k++) {
                complexMatrix[j][k] -= factor * complexMatrix[i][k];
            }

            complexVector[j] -= factor * complexVector[i];
        }
    }

    for(int i = numNodes - 1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            complexVector[j] -= complexMatrix[j][i] * complexVector[i];
            complexMatrix[j][i] = 0;
        }

        if(complexMatrix[i][i] == 0) {
            continue;
        }

        complexVector[i] /= complexMatrix[i][i];
        complexMatrix[i][i] = 1;
    }
}

void printSolution() {
    printf("Nodes:\n");

    for(int i = 1; i < numNodes; i++) {
        printf("%d: %lf + %lfi\n", i, creal(complexVector[i]), cimag(complexVector[i]));
    }

    printf("\n");
}

int main() {
    numNodes = 5;

    addComponent(1, 2, 100);
    addComponent(2, 3, 500);
    addComponent(3, 0, 50);
    addComponent(1, 0, 200);
    addComponent(2, 0, 150);
    addComponent(4, 5, 500);
    addComponent(5, 0, 100);

    initializeMatrix();
    fillMatrix();
    solveMatrix();
    printSolution();

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_LINES 100

typedef struct {
    int node1;
    int node2;
    double value;
} Component;

Component components[MAX_LINES];
int numNodes;
int numComp;
double G[MAX_NODES][MAX_NODES];
double B[MAX_NODES];
double voltage[MAX_NODES];

void addComponent(int node1, int node2, double value) {
    components[numComp].node1 = node1;
    components[numComp].node2 = node2;
    components[numComp].value = value;
    numComp++;
}

void stampComponents() {
    int i;
    for (i = 0; i < numComp; i++) {
        int node1 = components[i].node1;
        int node2 = components[i].node2;
        double value = components[i].value;
        if ((node1 == 0) || (node2 == 0)) {
            if (node1 == 0) {
                G[node2][node2] += 1 / value;
            } else {
                G[node1][node1] += 1 / value;
            }
            B[0] -= voltage[node1] / value - voltage[node2] / value;
        } else {
            G[node1][node1] += 1 / value;
            G[node2][node2] += 1 / value;
            G[node1][node2] -= 1 / value;
            G[node2][node1] -= 1 / value;
        }
    }
}

void solve() {
    int i, j, k;
    for (i = 1; i < numNodes; i++) {
        for (j = 1; j < numNodes; j++) {
            if (i == j) continue;
            if (G[i][j] == 0) continue;
            for (k = 1; k < numNodes; k++) {
                if ((k == i) || (k == j)) continue;
                G[i][k] -= G[j][k] * (G[i][j] / G[j][j]);
            }
            B[i] -= B[j] * (G[i][j] / G[j][j]);
            G[i][j] = 0;
        }
    }
    for (i = 1; i < numNodes; i++) {
        voltage[i] = B[i];
        for (j = 1; j < numNodes; j++) {
            if (i == j) continue;
            voltage[i] -= voltage[j] * G[i][j];
        }
        voltage[i] /= G[i][i];
    }
}

int main() {
    numNodes = 3;
    voltage[1] = 10;
    addComponent(1, 2, 1000);
    addComponent(2, 3, 0.001);
    stampComponents();
    solve();
    printf("Voltage at node 1: %f\n", voltage[1]);
    return 0;
}
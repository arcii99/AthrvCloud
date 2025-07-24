//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define PI 3.141592653589793

typedef struct node {
    char type;
    double value;
    int forward;
    int reverse;
} Node;

typedef struct component {
    double value;
    int node1;
    int node2;
} Component;

Node nodes[MAX_NODES];
Component components[MAX_NODES];
int nodeCount = 0;
int componentCount = 0;

double getVoltage(int n) {
    Node node = nodes[n];
    if (node.type == 'V') {
        return node.value;
    } else if (node.type == 'R') {
        return nodes[node.forward].value - nodes[node.reverse].value;
    } else {
        return 0;
    }
}

double getCurrent(int n) {
    Node node = nodes[n];
    if (node.type == 'V') {
        return 0;
    } else if (node.type == 'R') {
        return (nodes[node.forward].value - nodes[node.reverse].value) / node.value;
    } else {
        return 0;
    }
}

void printResults() {
    printf("Results:\n");
    printf("Node Voltages:\n");
    for (int i = 1; i <= nodeCount; i++) {
        Node node = nodes[i];
        printf("Node %d: %f V\n", i, node.value);
    }
    printf("Component Currents:\n");
    for (int i = 1; i <= componentCount; i++) {
        Component comp = components[i];
        printf("Component %d: %f A\n", i, (getCurrent(comp.node2) - getCurrent(comp.node1)) / comp.value);
    }
}

void simulate(double dt, int steps) {
    double t = 0;
    for (int i = 0; i < steps; i++) {
        for (int j = 1; j <= componentCount; j++) {
            Component comp = components[j];
            nodes[comp.node1].value += getVoltage(comp.node1) / comp.value * dt;
            nodes[comp.node2].value += getVoltage(comp.node2) / comp.value * dt;
        }
        for (int j = 1; j <= nodeCount; j++) {
            Node node = nodes[j];
            if (node.type == 'C') {
                node.value += getCurrent(j) * dt / node.value;
            }
        }
        t += dt;
    }
}

int main() {
    nodes[++nodeCount] = (Node) { .type='G', .value=0, .forward=0, .reverse=0 }; // ground node
    nodes[++nodeCount] = (Node) { .type='V', .value=1, .forward=1, .reverse=0 };
    nodes[++nodeCount] = (Node) { .type='C', .value=1, .forward=2, .reverse=3 };
    nodes[++nodeCount] = (Node) { .type='R', .value=1, .forward=3, .reverse=0 };

    components[++componentCount] = (Component) { .value=1, .node1=1, .node2=2 };
    components[++componentCount] = (Component) { .value=1, .node1=2, .node2=3 };
    components[++componentCount] = (Component) { .value=1, .node1=4, .node2=3 };

    simulate(0.01, 1000);
    printResults();

    return 0;
}
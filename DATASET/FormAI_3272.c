//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_BRANCHES 2000

int node_index = 0;
int branch_index = 0;

struct Node {
    int id;
    double voltage;
};

struct Branch {
    int n1, n2;
    double current;
    double resistance;
};

struct Circuit {
    struct Node nodes[MAX_NODES];
    struct Branch branches[MAX_BRANCHES];
};

void add_node(struct Circuit* circuit, double voltage) {
    circuit->nodes[node_index].id = node_index;
    circuit->nodes[node_index].voltage = voltage;
    node_index++;
}

void add_branch(struct Circuit* circuit, int n1, int n2, double resistance) {
    circuit->branches[branch_index].n1 = n1;
    circuit->branches[branch_index].n2 = n2;
    circuit->branches[branch_index].resistance = resistance;
    branch_index++;
}

void simulate(struct Circuit* circuit) {
    double current = 0.0;
    double total_resistance = 0.0;
    for (int i = 0; i < branch_index; i++) {
        total_resistance += circuit->branches[i].resistance;
    }
    current = circuit->nodes[0].voltage / total_resistance;

    for (int i = 0; i < branch_index; i++) {
        circuit->branches[i].current = current;
        double delta_v = (circuit->nodes[circuit->branches[i].n1].voltage -
            circuit->nodes[circuit->branches[i].n2].voltage);
        circuit->branches[i].current += delta_v / circuit->branches[i].resistance;
        circuit->nodes[circuit->branches[i].n1].voltage -= delta_v;
        circuit->nodes[circuit->branches[i].n2].voltage += delta_v;
    }
}

int main() {
    struct Circuit circuit;
    memset(&circuit, 0, sizeof(circuit));

    add_node(&circuit, 5.0);
    add_node(&circuit, 0.0);
    add_branch(&circuit, 0, 1, 500.0);
    add_branch(&circuit, 0, 1, 1000.0);
    add_branch(&circuit, 0, 1, 2000.0);

    for (int i = 0; i < 10; i++) {
        simulate(&circuit);
        printf("Voltage at node 1: %f\n", circuit.nodes[0].voltage);
    }

    return 0;
}
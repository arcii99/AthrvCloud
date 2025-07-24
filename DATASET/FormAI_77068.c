//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_RESISTORS 100

typedef struct Resistor {
    int node1;
    int node2;
    double resistance;
} Resistor;

typedef struct Node {
    int num_resistors;
    int resistors[MAX_RESISTORS];
    double voltage;
} Node;

Resistor resistors[MAX_RESISTORS];
Node nodes[MAX_NODES];
int num_resistors = 0;
int num_nodes = 0;

void add_resistor(int n1, int n2, double r) {
    Resistor resistor = {n1, n2, r};
    resistors[num_resistors++] = resistor;

    nodes[n1].resistors[nodes[n1].num_resistors++] = num_resistors - 1;
    nodes[n2].resistors[nodes[n2].num_resistors++] = num_resistors - 1;
}

void solve_circuit() {
    double resistance_matrix[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < num_resistors; i++) {
        int n1 = resistors[i].node1;
        int n2 = resistors[i].node2;
        double r = resistors[i].resistance;
        resistance_matrix[n1][n1] += 1.0 / r;
        resistance_matrix[n1][n2] -= 1.0 / r;
        resistance_matrix[n2][n2] += 1.0 / r;
        resistance_matrix[n2][n1] -= 1.0 / r;
    }

    for (int i = 0; i < num_nodes; i++) {
        if (i == 0) {
            nodes[i].voltage = 0;
            continue;
        }

        double max_conductance = 0;
        int max_conductance_node = -1;

        for (int j = 0; j < num_nodes; j++) {
            if (j == i) {
                continue;
            }

            double conductance = resistance_matrix[i][j];
            if (conductance > max_conductance) {
                max_conductance = conductance;
                max_conductance_node = j;
            }
        }

        nodes[i].voltage = nodes[max_conductance_node].voltage + max_conductance;
    }
}

int main() {
    add_resistor(0, 1, 100);
    add_resistor(0, 2, 200);
    add_resistor(1, 2, 50);
    add_resistor(1, 3, 75);
    add_resistor(2, 3, 125);

    num_nodes = 4;

    solve_circuit();

    printf("Node Voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2fV\n", i, nodes[i].voltage);
    }

    return 0;
}
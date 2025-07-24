//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_NUM 100

typedef struct Component {
    int n1, n2;
    double value;
} component;

int node_map[MAX_NODE_NUM];
component comp[MAX_NODE_NUM];
double node_volt[MAX_NODE_NUM];
double edge_current[MAX_NODE_NUM];

int node_num, comp_num;

int get_node_id(int node) {
    if (!node_map[node]) {
        node_map[node] = ++node_num;
    }
    return node_map[node];
}

void add_component(int n1, int n2, double value) {
    comp[comp_num].n1 = n1;
    comp[comp_num].n2 = n2;
    comp[comp_num].value = value;
    comp_num++;
}

void init_node_volt(double v) {
    for (int i = 1; i <= node_num; i++) {
        node_volt[i] = v;
    }
}

void simulate() {
    int cnt = 0;
    while (cnt++ < 100000) {
        int converged = 1;
        for (int i = 0; i < comp_num; i++) {
            int n1 = comp[i].n1, n2 = comp[i].n2;
            double g = 1.0 / comp[i].value;
            double v = node_volt[n1] - node_volt[n2];
            double i = g * v;

            if (n1 != 0) {
                edge_current[n1] += i;
                if (n1 != 1) {
                    node_volt[n1] -= i * 1e-12;
                }
            }

            if (n2 != 0) {
                edge_current[n2] -= i;
                if (n2 != 1) {
                    node_volt[n2] += i * 1e-12;
                }
            }
            if (converged && i > 1e-6) {
                converged = 0;
            }
        }
        if (converged) {
            printf("Converged after %d iterations.\n", cnt);
            return;
        }
    }
    printf("Failed to converge after %d iterations.\n", cnt);
}

int main() {
    add_component(0, 1, 5.0);
    add_component(0, 2, 10.0);
    add_component(1, 2, 7.0);
    add_component(1, 3, 8.0);
    add_component(2, 3, 6.0);

    init_node_volt(1.0);
    simulate();

    return 0;
}
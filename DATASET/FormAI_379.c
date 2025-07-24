//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_RESISTORS 20

int num_nodes;
int num_resistors;
int r_index;

int r_nodes[MAX_RESISTORS][2];
double r_values[MAX_RESISTORS];

double node_voltage[MAX_NODES];
double node_voltage_new[MAX_NODES];
double node_rhs[MAX_NODES];
double node_rhs_new[MAX_NODES];
double A_matrix[MAX_NODES][MAX_NODES];

void add_resistor(int n1, int n2, double resistance)
{
    r_nodes[r_index][0] = n1;
    r_nodes[r_index][1] = n2;
    r_values[r_index] = resistance;
    r_index++;
}

void build_A_matrix()
{
    int i, j, r;
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            A_matrix[i][j] = 0.0;
        }
    }
    for (r = 0; r < num_resistors; r++) {
        int n1 = r_nodes[r][0];
        int n2 = r_nodes[r][1];
        double G = 1.0 / r_values[r];
        A_matrix[n1][n1] += G;
        A_matrix[n2][n2] += G;
        A_matrix[n1][n2] -= G;
        A_matrix[n2][n1] -= G;
    }
}

void build_rhs()
{
    int i, r;
    for (i = 0; i < num_nodes; i++) {
        node_rhs[i] = 0.0;
    }
    for (r = 0; r < num_resistors; r++) {
        int n1 = r_nodes[r][0];
        int n2 = r_nodes[r][1];
        double V = node_voltage[n1] - node_voltage[n2];
        double I = V / r_values[r];
        node_rhs[n1] += I;
        node_rhs[n2] -= I;
    }
}

void solve()
{
    int i, j, k;
    double error = 1.0;
    while (error > 0.0001) {
        for (i = 0; i < num_nodes; i++) {
            node_voltage_new[i] = node_rhs[i];
            for (j = 0; j < num_nodes; j++) {
                if (i != j) {
                    node_voltage_new[i] -= A_matrix[i][j] * node_voltage[j];
                }
            }
            node_voltage_new[i] /= A_matrix[i][i];
        }
        error = 0.0;
        for (k = 0; k < num_nodes; k++) {
            error += fabs(node_voltage_new[k] - node_voltage[k]);
            node_voltage[k] = node_voltage_new[k];
        }
    }
}

int main()
{
    num_nodes = 3;
    num_resistors = 2;
    r_index = 0;
    add_resistor(0, 1, 1000.0);
    add_resistor(1, 2, 2000.0);
    build_A_matrix();
    build_rhs();
    solve();
    printf("Node voltages:\n");
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %f\n", i, node_voltage[i]);
    }
    return 0;
}
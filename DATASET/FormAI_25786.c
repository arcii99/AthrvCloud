//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINES 50
#define MAX_NODES 50

int matrix[MAX_NODES][MAX_NODES];
int resistors[MAX_LINES];
int nodes[MAX_LINES][2];
int node_count = 0;
int line_count = 0;

void add_node(int node) {
    for (int i = 0; i < node_count; i++) {
        if (nodes[i][0] == node || nodes[i][1] == node) {
            return;
        }
    }
    if (node_count == MAX_NODES) {
        printf("Too many nodes\n");
        exit(1);
    }
    nodes[node_count][0] = node;
    nodes[node_count][1] = node;
    node_count++;
}

int node_index(int node) {
    for (int i = 0; i < node_count; i++) {
        if (nodes[i][0] == node || nodes[i][1] == node) {
            return i;
        }
    }
    add_node(node);
    return node_count-1;
}

void add_resistor(int n1, int n2, double resistance) {
    int i1 = node_index(n1);
    int i2 = node_index(n2);
    matrix[i1][i1] += 1/resistance;
    matrix[i1][i2] -= 1/resistance;
    matrix[i2][i1] -= 1/resistance;
    matrix[i2][i2] += 1/resistance;
    resistors[line_count] = resistance;
    nodes[i1][1] = n1;
    nodes[i2][1] = n2;
    line_count++;
}

void solve_matrix(double* voltage, double* current) {
    double a[MAX_NODES*MAX_NODES];
    double x[MAX_NODES];
    double b[MAX_NODES];
    for (int i = 0; i < node_count; i++) {
        for (int j = 0; j < node_count; j++) {
            a[i*node_count+j] = (double)matrix[i][j];
        }
        b[i] = 0;
    }
    b[0] = voltage[0];
    for (int i = 0; i < line_count; i++) {
        int i1 = node_index(nodes[i][0]);
        int i2 = node_index(nodes[i][1]);
        b[i1] -= current[i];
        b[i2] += current[i];
    }
    double det = 1.0;
    for (int k = 0; k < node_count-1; k++) {
        for (int i = k+1; i < node_count; i++) {
            double factor = a[i*node_count+k]/a[k*node_count+k];
            for (int j = k+1; j < node_count; j++) {
                a[i*node_count+j] -= factor * a[k*node_count+j];
            }
            b[i] -= factor * b[k];
        }
    det *= a[k*node_count+k];
    }
    det *= a[node_count*node_count-1];
    for (int i = node_count-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < node_count; j++) {
            sum += a[i*node_count+j] * x[j];
        }
        x[i] = (b[i] - sum)/a[i*node_count+i];
    }
    for (int i = 0; i < line_count; i++) {
        int i1 = node_index(nodes[i][0]);
        int i2 = node_index(nodes[i][1]);
        current[i] = (x[i1] - x[i2])/resistors[i];
    }
}

int main() {
    double voltage[1] = {5.0};
    double current[MAX_LINES];
    add_resistor(1,2,100);
    add_resistor(2,3,200);
    add_resistor(3,1,50);
    solve_matrix(voltage,current);
    for (int i = 0; i < line_count; i++) {
        printf("Current through resistor %d: %f\n", i, current[i]);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_VAL 100000.0

typedef enum { 
    RESISTOR, 
    CAPACITOR, 
    INDUCTOR, 
    DC_SOURCE, 
    AC_SOURCE, 
    DIODE, 
    TRANSISTOR, 
    OP_AMP
} element_t;

typedef struct {
    int n1, n2;
    double value;
    element_t type;
} element_s;

element_s elements[MAX_NODES];
double matrix[MAX_NODES][MAX_NODES+1];
int num_nodes = 0;
int num_elements = 0;

void add_element(int n1, int n2, double value, element_t type) {
    elements[num_elements].n1 = n1;
    elements[num_elements].n2 = n2;
    elements[num_elements].value = value;
    elements[num_elements].type = type;
    num_elements++;
}

void build_matrix() {
    int i, j;
    for (i = 0; i <= num_nodes; i++) {
        for (j = 0; j <= num_nodes; j++) {
            matrix[i][j] = 0.0;
        }
    }

    for (i = 0; i < num_elements; i++) {
        switch (elements[i].type) {
            case RESISTOR:
                matrix[elements[i].n1][elements[i].n1] += 1.0 / elements[i].value;
                matrix[elements[i].n2][elements[i].n2] += 1.0 / elements[i].value;
                matrix[elements[i].n1][elements[i].n2] -= 1.0 / elements[i].value;
                matrix[elements[i].n2][elements[i].n1] -= 1.0 / elements[i].value;
                break;

            case CAPACITOR:
                matrix[elements[i].n1][elements[i].n1] += elements[i].value;
                matrix[elements[i].n2][elements[i].n2] += elements[i].value;
                matrix[elements[i].n1][elements[i].n2] -= elements[i].value;
                matrix[elements[i].n2][elements[i].n1] -= elements[i].value;
                matrix[num_nodes][elements[i].n1] += 1.0;
                matrix[num_nodes][elements[i].n2] -= 1.0;
                break;

            case INDUCTOR:
                matrix[elements[i].n1][elements[i].n1] += 1e-12;
                matrix[elements[i].n2][elements[i].n2] += 1e-12;
                matrix[elements[i].n1][elements[i].n2] -= 1e-12;
                matrix[elements[i].n2][elements[i].n1] -= 1e-12;
                break;

            case DC_SOURCE:
                matrix[elements[i].n1][num_nodes] += 1.0;
                matrix[elements[i].n2][num_nodes] -= 1.0;
                matrix[num_nodes][elements[i].n1] -= 1.0;
                matrix[num_nodes][elements[i].n2] += 1.0;
                matrix[num_nodes][num_nodes] -= elements[i].value;
                break;

            case AC_SOURCE:
                matrix[elements[i].n1][num_nodes] += 1.0;
                matrix[elements[i].n2][num_nodes] -= 1.0;
                matrix[num_nodes][elements[i].n1] -= 1.0;
                matrix[num_nodes][elements[i].n2] += 1.0;
                matrix[num_nodes][num_nodes] -= elements[i].value;
                break;

            case DIODE:
                break;

            case TRANSISTOR:
                break;

            case OP_AMP:
                break;
        }
    }
}

void solve_matrix(double* result) {
    int i, j, k;
    double tmp, max_val;
    int max_row;

    for (i = 0; i < num_nodes; i++) {
        max_row = i;
        max_val = matrix[max_row][i];

        for (j = i+1; j < num_nodes; j++) {
            if (fabs(matrix[j][i]) > fabs(max_val)) {
                max_row = j;
                max_val = matrix[max_row][i];
            }
        }

        if (max_row != i) {
            for (j = 0; j <= num_nodes; j++) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[max_row][j];
                matrix[max_row][j] = tmp;
            }
        }

        for (j = i+1; j < num_nodes; j++) {
            tmp = matrix[j][i] / matrix[i][i];
            for (k = i+1; k <= num_nodes; k++) {
                matrix[j][k] -= tmp * matrix[i][k];
            }
        }
    }

    result[num_nodes-1] = matrix[num_nodes-1][num_nodes] / matrix[num_nodes-1][num_nodes-1];
    for (i = num_nodes-2; i >= 0; i--) {
        tmp = 0.0;
        for (j = i+1; j < num_nodes; j++) {
            tmp += matrix[i][j] * result[j];
        }
        result[i] = (matrix[i][num_nodes] - tmp) / matrix[i][i];
    }
}

int main() {
    add_element(0, 1, 10000, RESISTOR);
    add_element(1, 2, 0.000001, CAPACITOR);
    add_element(0, 2, 1000, RESISTOR);
    add_element(2, 3, 0.000001, CAPACITOR);
    add_element(3, 0, 10000, RESISTOR);
    build_matrix();

    double result[MAX_NODES];
    solve_matrix(result);

    printf("Voltage at node 1: %lf\n", result[0]);
    printf("Voltage at node 2: %lf\n", result[1]);
    printf("Voltage at node 3: %lf\n", result[2]);
    printf("Voltage at node 4: %lf\n", result[3]);

    return 0;
}
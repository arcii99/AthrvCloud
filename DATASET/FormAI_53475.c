//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 2000
#define MAX_STEPS 1000000

struct element {
    char *name;
    int nodes[2];
    double value;
    int type;
} circuit_element[MAX_NODES];

int num_nodes, num_elements;
double matrix[MAX_NODES][MAX_NODES];
double rhs[MAX_NODES];

void stamp_resistor(int n1, int n2, double resistance) {
    double conductance = 1 / resistance;
    matrix[n1][n1] += conductance;
    matrix[n2][n2] += conductance;
    matrix[n1][n2] -= conductance;
    matrix[n2][n1] -= conductance;
}

void stamp_capacitor(int n1, int n2, double capacitance, double timestep) {
    double conductance = 2 * capacitance / timestep;
    matrix[n1][n1] += conductance;
    matrix[n2][n2] += conductance;
    matrix[n1][n2] -= conductance;
    matrix[n2][n1] -= conductance;
}

void stamp_inductor(int n1, int n2, double inductance, double timestep) {
    double conductance = 2 * inductance / timestep;
    matrix[n1][n1] += conductance;
    matrix[n2][n2] += conductance;
    matrix[n1][n2] -= conductance;
    matrix[n2][n1] -= conductance;
}

void stamp_current_source(int n1, int n2, double current) {
    rhs[n1] -= current;
    rhs[n2] += current;
}

void stamp_voltage_source(int n1, int n2, double voltage) {
    matrix[n1][num_nodes] -= voltage;
    matrix[n2][num_nodes] += voltage;
    matrix[num_nodes][n1] += 1;
    matrix[num_nodes][n2] -= 1;
}

void parse_and_execute(char line[]) {
    char *token = strtok(line, " \n");

    if (token == NULL || *token == '#') {
        return;
    }

    if (strcmp(token, "R") == 0) {
        int n1 = atoi(strtok(NULL, " \n"));
        int n2 = atoi(strtok(NULL, " \n"));
        double resistance = atof(strtok(NULL, " \n"));
        stamp_resistor(n1, n2, resistance);
    } else if (strcmp(token, "C") == 0) {
        int n1 = atoi(strtok(NULL, " \n"));
        int n2 = atoi(strtok(NULL, " \n"));
        double capacitance = atof(strtok(NULL, " \n"));
        stamp_capacitor(n1, n2, capacitance, 0.01);
    } else if (strcmp(token, "L") == 0) {
        int n1 = atoi(strtok(NULL, " \n"));
        int n2 = atoi(strtok(NULL, " \n"));
        double inductance = atof(strtok(NULL, " \n"));
        stamp_inductor(n1, n2, inductance, 0.01);
    } else if (strcmp(token, "I") == 0) {
        int n1 = atoi(strtok(NULL, " \n"));
        int n2 = atoi(strtok(NULL, " \n"));
        double current = atof(strtok(NULL, " \n"));
        stamp_current_source(n1, n2, current);
    } else if (strcmp(token, "V") == 0) {
        int n1 = atoi(strtok(NULL, " \n"));
        int n2 = atoi(strtok(NULL, " \n"));
        double voltage = atof(strtok(NULL, " \n"));
        stamp_voltage_source(n1, n2, voltage);
    } else {
        printf("Error: unknown token %s\n", token);
        exit(1);
    }
}

void gauss_solve() {
    int i, j, k, maxrow;
    double temp, max;

    for (i = 0; i < num_nodes; i++) {
        maxrow = i;
        max = matrix[i][i];

        for (j = i + 1; j < num_nodes; j++) {
            if (fabs(matrix[j][i]) > fabs(max)) {
                maxrow = j;
                max = matrix[j][i];
            }
        }

        for (k = i; k <= num_nodes; k++) {
            temp = matrix[i][k];
            matrix[i][k] = matrix[maxrow][k];
            matrix[maxrow][k] = temp;
        }

        for (j = i + 1; j < num_nodes; j++) {
            for (k = i + 1; k <= num_nodes; k++) {
                matrix[j][k] -= matrix[i][k] * (matrix[j][i] / matrix[i][i]);
            }
            rhs[j] -= rhs[i] * (matrix[j][i] / matrix[i][i]);
            matrix[j][i] = 0;
        }
    }

    for (i = num_nodes - 1; i >= 0; i--) {
        temp = rhs[i];
        for (j = i + 1; j < num_nodes; j++) {
            temp -= matrix[i][j] * rhs[j];
        }
        rhs[i] = temp / matrix[i][i];
    }
}

int main(int argc, char *argv[]) {
    char line[200];
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <circuit file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, 200, file) != NULL) {
        parse_and_execute(line);
    }

    fclose(file);

    num_nodes = num_elements + 1;

    gauss_solve();

    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes - 1; i++) {
        printf("%d: %f\n", i + 1, rhs[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100

int num_nodes = 0, num_voltages = 0, num_currents = 0, num_resistors = 0, num_capacitors = 0, num_inductors = 0;
char node_names[MAX_NODES][10];

typedef struct Resistor {
    char name[10];
    double resistance;
    int node1, node2;
} Resistor;

typedef struct Capacitor {
    char name[10];
    double capacitance;
    int node1, node2;
} Capacitor;

typedef struct Inductor {
    char name[10];
    double inductance;
    int node1, node2;
} Inductor;

typedef struct VoltageSource {
    char name[10];
    double magnitude, phase, frequency;
    int node1, node2;
} VoltageSource;

typedef struct CurrentSource {
    char name[10];
    double magnitude, phase, frequency;
    int node1, node2;
} CurrentSource;

typedef struct Node {
    int id;
    double voltage;
} Node;

Resistor resistors[MAX_NODES];
Capacitor capacitors[MAX_NODES];
Inductor inductors[MAX_NODES];
VoltageSource voltage_sources[MAX_NODES];
CurrentSource current_sources[MAX_NODES];
Node nodes[MAX_NODES];

void add_node(char *name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node_names[i], name) == 0) {
            return;
        }
    }
    strcpy(node_names[num_nodes], name);
    num_nodes++;
}

int get_node_id(char *name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node_names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_resistor(char *name, double resistance, char *node1_name, char *node2_name) {
    for (int i = 0; i < num_resistors; i++) {
        if (strcmp(resistors[i].name, name) == 0) {
            return;
        }
    }
    int node1_id = get_node_id(node1_name);
    if (node1_id == -1) {
        add_node(node1_name);
        node1_id = num_nodes - 1;
    }
    int node2_id = get_node_id(node2_name);
    if (node2_id == -1) {
        add_node(node2_name);
        node2_id = num_nodes - 1;
    }
    Resistor r;
    strcpy(r.name, name);
    r.resistance = resistance;
    r.node1 = node1_id;
    r.node2 = node2_id;
    resistors[num_resistors] = r;
    num_resistors++;
}

void add_capacitor(char *name, double capacitance, char *node1_name, char *node2_name) {
    for (int i = 0; i < num_capacitors; i++) {
        if (strcmp(capacitors[i].name, name) == 0) {
            return;
        }
    }
    int node1_id = get_node_id(node1_name);
    if (node1_id == -1) {
        add_node(node1_name);
        node1_id = num_nodes - 1;
    }
    int node2_id = get_node_id(node2_name);
    if (node2_id == -1) {
        add_node(node2_name);
        node2_id = num_nodes - 1;
    }
    Capacitor c;
    strcpy(c.name, name);
    c.capacitance = capacitance;
    c.node1 = node1_id;
    c.node2 = node2_id;
    capacitors[num_capacitors] = c;
    num_capacitors++;
}

void add_inductor(char *name, double inductance, char *node1_name, char *node2_name) {
    for (int i = 0; i < num_inductors; i++) {
        if (strcmp(inductors[i].name, name) == 0) {
            return;
        }
    }
    int node1_id = get_node_id(node1_name);
    if (node1_id == -1) {
        add_node(node1_name);
        node1_id = num_nodes - 1;
    }
    int node2_id = get_node_id(node2_name);
    if (node2_id == -1) {
        add_node(node2_name);
        node2_id = num_nodes - 1;
    }
    Inductor l;
    strcpy(l.name, name);
    l.inductance = inductance;
    l.node1 = node1_id;
    l.node2 = node2_id;
    inductors[num_inductors] = l;
    num_inductors++;
}

void add_voltage_source(char *name, double magnitude, double phase, double frequency, char *node1_name, char *node2_name) {
    for (int i = 0; i < num_voltages; i++) {
        if (strcmp(voltage_sources[i].name, name) == 0) {
            return;
        }
    }
    int node1_id = get_node_id(node1_name);
    if (node1_id == -1) {
        add_node(node1_name);
        node1_id = num_nodes - 1;
    }
    int node2_id = get_node_id(node2_name);
    if (node2_id == -1) {
        add_node(node2_name);
        node2_id = num_nodes - 1;
    }
    VoltageSource v;
    strcpy(v.name, name);
    v.magnitude = magnitude;
    v.phase = phase;
    v.frequency = frequency;
    v.node1 = node1_id;
    v.node2 = node2_id;
    voltage_sources[num_voltages] = v;
    num_voltages++;
}

void add_current_source(char *name, double magnitude, double phase, double frequency, char *node1_name, char *node2_name) {
    for (int i = 0; i < num_currents; i++) {
        if (strcmp(current_sources[i].name, name) == 0) {
            return;
        }
    }
    int node1_id = get_node_id(node1_name);
    if (node1_id == -1) {
        add_node(node1_name);
        node1_id = num_nodes - 1;
    }
    int node2_id = get_node_id(node2_name);
    if (node2_id == -1) {
        add_node(node2_name);
        node2_id = num_nodes - 1;
    }
    CurrentSource c;
    strcpy(c.name, name);
    c.magnitude = magnitude;
    c.phase = phase;
    c.frequency = frequency;
    c.node1 = node1_id;
    c.node2 = node2_id;
    current_sources[num_currents] = c;
    num_currents++;
}

void print_matrix(double A[MAX_NODES][MAX_NODES], double b[MAX_NODES]) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%f ", A[i][j]);
        }
        printf(" | %f\n", b[i]);
    }
}

void solve_system(double A[MAX_NODES][MAX_NODES], double b[MAX_NODES], double x[MAX_NODES]) {
    double eps = 1e-6;
    for (int k = 0; k < num_nodes; k++) {
        // find the pivot row
        int pivot = k;
        double max_val = fabs(A[k][k]);
        for (int i = k+1; i < num_nodes; i++) {
            if (fabs(A[i][k]) > max_val) {
                max_val = fabs(A[i][k]);
                pivot = i;
            }
        }
        if (fabs(A[pivot][k]) < eps) {
            printf("Error: Singular matrix!\n");
            return;
        }
        // swap rows if necessary
        if (pivot != k) {
            for (int j = k; j < num_nodes; j++) {
                double temp = A[k][j];
                A[k][j] = A[pivot][j];
                A[pivot][j] = temp;
            }
            double temp = b[k];
            b[k] = b[pivot];
            b[pivot] = temp;
        }
        // eliminate rows
        for (int i = k+1; i < num_nodes; i++) {
            double ratio = A[i][k] / A[k][k];
            for (int j = k; j < num_nodes; j++) {
                A[i][j] -= ratio * A[k][j];
            }
            b[i] -= ratio * b[k];
        }
    }
    // back substitution
    for (int i = num_nodes-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < num_nodes; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
}

void solve_circuit(double frequency) {
    double A[MAX_NODES][MAX_NODES] = {0};
    double b[MAX_NODES] = {0};
    double x[MAX_NODES] = {0};
    int V_count = 0;
    for (int i = 0; i < num_resistors; i++) {
        int node1 = resistors[i].node1;
        int node2 = resistors[i].node2;
        if (node1 != -1 && node2 != -1) {
            double conductance = 1.0 / resistors[i].resistance;
            A[node1][node1] += conductance;
            A[node1][node2] -= conductance;
            A[node2][node1] -= conductance;
            A[node2][node2] += conductance;
        }
    }
    for (int i = 0; i < num_capacitors; i++) {
        int node1 = capacitors[i].node1;
        int node2 = capacitors[i].node2;
        if (node1 != -1 && node2 != -1) {
            double impedance = -1.0 / (capacitors[i].capacitance * 2 * M_PI * frequency);
            A[node1][node1] += 1.0 / impedance;
            A[node1][node2] -= 1.0 / impedance;
            A[node2][node1] -= 1.0 / impedance;
            A[node2][node2] += 1.0 / impedance;
        }
    }
    for (int i = 0; i < num_inductors; i++) {
        int node1 = inductors[i].node1;
        int node2 = inductors[i].node2;
        if (node1 != -1 && node2 != -1) {
            double impedance = inductors[i].inductance * 2 * M_PI * frequency;
            A[node1][node1] += impedance;
            A[node1][node2] -= impedance;
            A[node2][node1] -= impedance;
            A[node2][node2] += impedance;
        }
    }
    for (int i = 0; i < num_voltages; i++) {
        int node1 = voltage_sources[i].node1;
        int node2 = voltage_sources[i].node2;
        if (node1 != -1 && node2 != -1) {
            double magnitude = voltage_sources[i].magnitude;
            double phase = voltage_sources[i].phase;
            double impedance = -magnitude / (2 * M_PI * frequency);
            double real_impedance = impedance * cos(phase);
            double imaginary_impedance = impedance * sin(phase);
            A[node1][num_nodes + V_count] = 1.0;
            A[node2][num_nodes + V_count] = -1.0;
            A[num_nodes + V_count][node1] = 1.0;
            A[num_nodes + V_count][node2] = -1.0;
            A[num_nodes + V_count][num_nodes + V_count] = real_impedance;
            A[num_nodes + V_count][num_nodes + V_count + 1] = imaginary_impedance;
            b[num_nodes + V_count] = magnitude;
            V_count += 2;
        }
    }
    for (int i = 0; i < num_currents; i++) {
        int node1 = current_sources[i].node1;
        int node2 = current_sources[i].node2;
        if (node1 != -1 && node2 != -1) {
            double magnitude = current_sources[i].magnitude;
            double phase = current_sources[i].phase;
            double omega = 2 * M_PI * frequency;
            b[node1] += magnitude * cos(phase);
            b[node2] += -magnitude * cos(phase);
            b[node1+num_nodes] += magnitude * sin(phase);
            b[node2+num_nodes] += -magnitude * sin(phase);
            A[node1][node1] += cos(phase) * omega;
            A[node1][node1+num_nodes] += sin(phase) * omega;
            A[node1+num_nodes][node1] += -sin(phase) * omega;
            A[node1+num_nodes][node1+num_nodes] += cos(phase) * omega;
            A[node2][node2] += cos(phase) * omega;
            A[node2][node2+num_nodes] += sin(phase) * omega;
            A[node2+num_nodes][node2] += -sin(phase) * omega;
            A[node2+num_nodes][node2+num_nodes] += cos(phase) * omega;
        }
    }
    print_matrix(A, b);
    solve_system(A, b, x);
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].voltage = x[i];
        nodes[i].id = i;
    }
    printf("\nNode Voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: %f\n", node_names[i], nodes[i].voltage);
    }
}

int main() {
    add_resistor("r1", 1000.0, "n1", "n2");
    add_resistor("r2", 2200.0, "n2", "n3");
    add_resistor("r3", 4700.0, "n3", "n4");
    add_resistor("r4", 3300.0, "n2", "n4");
    add_capacitor("c1", 1e-6, "n2", "n3");
    add_inductor("l1", 220e-3, "n1", "n4");
    add_voltage_source("vs1", 10.0, 0.0, 1000.0, "n1", "n4");
    solve_circuit(1000.0);
    return 0;
}
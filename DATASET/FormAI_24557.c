//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_BRANCHES 30

typedef struct {
    int node1, node2;
    double value;
} Branch;

typedef struct {
    int branch_index1, branch_index2;
    double value;
} Stamp;

int nodes[MAX_BRANCHES+1][2];
int num_nodes, num_branches;
Branch branches[MAX_BRANCHES+1];
Stamp stamps[MAX_NODES*2+1];
int num_stamps;

double conductance(double value) {
    if (value > 0.0) {
        return 1.0/value;
    } else {
        return 0.0;
    }
}

void add_stamp(int i, int j, double value) {
    num_stamps++;
    stamps[num_stamps].branch_index1 = i;
    stamps[num_stamps].branch_index2 = j;
    stamps[num_stamps].value = value;
}

void stamp_resistor(int i, int j, double value) {
    double g = conductance(value);
    add_stamp(i, i, g);
    add_stamp(j, j, g);
    add_stamp(i, j, -g);
    add_stamp(j, i, -g);
}

void stamp_vsource(int i, int j, double value) {
    add_stamp(i, num_branches+1, 1.0);
    add_stamp(j, num_branches+1, -1.0);
    add_stamp(num_branches+1, i, 1.0);
    add_stamp(num_branches+1, j, -1.0);
    add_stamp(num_branches+1, num_branches+2, value);
}

void stamp_isource(int i, int j, double value) {
    add_stamp(i, j, value);
}

void stamp_voltage_probe(int i) {
    add_stamp(num_branches+1, i, 1.0);
}

void stamp_current_probe(int i) {
    add_stamp(i, num_branches+2, 1.0);
}

void stamp_ground(int i) {
    add_stamp(i, i, 1.0);
}

void solve_system() {
    int i, j, k;
    double factor;

    for (k = 1; k <= num_stamps; k++) {
        if (stamps[k].branch_index1 == num_branches+1) {
            stamps[k].value *= -1.0;
        } else if (stamps[k].branch_index2 == num_branches+1) {
            stamps[k].value *= -1.0;
        }
    }

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_stamps; j++) {
            if (stamps[j].branch_index1 == i) {
                stamps[j].branch_index1 = nodes[stamps[j].branch_index1][0];
            }
            if (stamps[j].branch_index2 == i) {
                stamps[j].branch_index2 = nodes[stamps[j].branch_index2][0];
            }
        }
    }

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_branches; j++) {
            if (nodes[j][0] == i) {
                nodes[j][1] = k;
                k++;
            }
        }
    }

    for (i = 1; i <= num_branches; i++) {
        factor = 1.0/stamps[nodes[i][1]].value;
        for (j = 1; j <= num_stamps; j++) {
            if (j != nodes[i][1]) {
                stamps[j].value -= factor * stamps[j].branch_index1;
                stamps[j].value -= factor * stamps[j].branch_index2;
            }
        }
    }

    for (i = 1; i <= num_branches; i++) {
        factor = 1.0/stamps[nodes[i][1]].value;
        for (j = 1; j <= num_stamps; j++) {
            if (j == nodes[i][1]) {
                stamps[j].value = factor;
                break;
            }
        }
    }

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_stamps; j++) {
            if (stamps[j].branch_index1 == i) {
                stamps[j].branch_index1 = nodes[stamps[j].branch_index1][1];
            }
            if (stamps[j].branch_index2 == i) {
                stamps[j].branch_index2 = nodes[stamps[j].branch_index2][1];
            }
        }
    }

    for (i = 1; i <= num_nodes; i++) {
        for (j = 1; j <= num_stamps; j++) {
            if (stamps[j].branch_index1 == num_branches+2) {
                stamps[j].value *= -1.0;
            } else if (stamps[j].branch_index2 == num_branches+2) {
                stamps[j].value *= -1.0;
            }
        }
    }

    for (i = 1; i <= num_branches+1; i++) {
        for (j = 1; j <= num_stamps; j++) {
            if (stamps[j].branch_index1 == i) {
                printf(" %.3f ", stamps[j].value);
            } else if (stamps[j].branch_index2 == i) {
                printf(" %.3f ", -stamps[j].value);
            }
        }
        if (i == num_branches+1) {
            printf(" |   0\n");
        } else {
            printf(" |   %c%d\n", branches[i].value > 0.0 ? '+' : '-', i);
        }
    }

    printf("\n");

    for (i = 1; i <= num_branches; i++) {
        for (j = 1; j <= num_stamps; j++) {
            if (stamps[j].branch_index1 == i) {
                printf(" %.3f ", stamps[j].value);
            } else if (stamps[j].branch_index2 == i) {
                printf(" %.3f ", -stamps[j].value);
            }
        }
        printf(" |   ");
        if (branches[i].node1 == 0) {
            printf("0");
        } else {
            printf("V%d", branches[i].node1);
        }
        printf(" - ");
        if (branches[i].node2 == 0) {
            printf("0");
        } else {
            printf("V%d", branches[i].node2);
        }
        printf(" = %f\n", branches[i].value);
    }

}

int main() {
    num_nodes = 0;
    num_branches = 0;
    num_stamps = 0;

    /* Adding resistors */
    stamp_resistor(1, 2, 4.0);
    stamp_resistor(1, 3, 8.0);
    stamp_resistor(2, 4, 3.0);
    stamp_resistor(3, 4, 5.0);

    /* Adding voltage sources */
    stamp_vsource(2, 3, 10.0);

    /* Adding current sources */
    stamp_isource(2, 4, -2.0);

    /* Adding voltage probes */
    stamp_voltage_probe(1);
    stamp_voltage_probe(4);

    /* Adding current probes */
    stamp_current_probe(2);
    stamp_current_probe(3);

    /* Adding ground */
    stamp_ground(4);

    solve_system();

    return 0;
}
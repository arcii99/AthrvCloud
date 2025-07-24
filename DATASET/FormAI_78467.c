//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_DEV_NAME_LEN 20

typedef struct {
    int t_num;
    double value;
} Transient;

typedef struct {
    char name[MAX_DEV_NAME_LEN];
    int node1, node2;
    double value;
} Device;

Device devices[MAX_NODES];
Transient transient[MAX_NODES];

double node_voltages[MAX_NODES];
double old_node_voltages[MAX_NODES];
double delta_rel;

int num_nodes;
int nodes[MAX_NODES];

double get_device_value(const Device *d, double voltage_diff)
{
    return d->value;
}

void update_node_voltages(void)
{
    for (int i = 0; i < num_nodes; i++) {
        old_node_voltages[i] = node_voltages[i];
        node_voltages[i] = 0.0;
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < MAX_NODES; k++) {
                if (j == k || i == k) {
                    continue;
                }
                if (devices[j].node1 == i && devices[j].node2 == k) {
                    double voltage_diff = old_node_voltages[i] - old_node_voltages[k];
                    double conductance = 1.0 / get_device_value(&devices[j], voltage_diff);
                    node_voltages[i] += conductance * old_node_voltages[k];
                    node_voltages[k] += conductance * old_node_voltages[i];
                }
                else if (devices[j].node2 == i && devices[j].node1 == k) {
                    double voltage_diff = old_node_voltages[k] - old_node_voltages[i];
                    double conductance = 1.0 / get_device_value(&devices[j], voltage_diff);
                    node_voltages[i] += conductance * old_node_voltages[k];
                    node_voltages[k] += conductance * old_node_voltages[i];
                }
            }
        }
    }
}

int transient_solver(double t_start, double t_end, double step_size)
{
    int num_steps = (int) round((t_end - t_start) / step_size);
    memcpy(old_node_voltages, node_voltages, sizeof(double) * MAX_NODES);
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < MAX_NODES; k++) {
                if (j == k || i == k) {
                    continue;
                }
                if (devices[j].node1 == i && devices[j].node2 == k) {
                    double voltage_diff = old_node_voltages[i] - old_node_voltages[k];
                    double conductance = 1.0 / get_device_value(&devices[j], voltage_diff);
                    node_voltages[i] += conductance * old_node_voltages[k];
                    node_voltages[k] += conductance * old_node_voltages[i];
                }
                else if (devices[j].node2 == i && devices[j].node1 == k) {
                    double voltage_diff = old_node_voltages[k] - old_node_voltages[i];
                    double conductance = 1.0 / get_device_value(&devices[j], voltage_diff);
                    node_voltages[i] += conductance * old_node_voltages[k];
                    node_voltages[k] += conductance * old_node_voltages[i];
                }
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        printf("%.6f, ", node_voltages[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    // initialize circuit
    num_nodes = 4;
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = i;
    }

    devices[0] = (Device){"V1", 0, 1, 5.0};
    devices[1] = (Device){"R1", 1, 2, 1000.0};
    devices[2] = (Device){"R2", 2, 3, 5000.0};
    devices[3] = (Device){"C1", 2, 0, 0.001};

    // initialize node voltages
    node_voltages[0] = 0.0;  // GND
    node_voltages[1] = 5.0;
    node_voltages[2] = 5.0 * 1000.0 / (1000.0 + 5000.0);
    node_voltages[3] = 0.0;  // GND

    // simulate transient response
    double t_start = 0.0;
    double t_end = 0.01;
    double step_size = 0.0001;
    transient_solver(t_start, t_end, step_size);

    return 0;
}
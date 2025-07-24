//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_DEVICES 1000

typedef struct node {
    int id;
    double voltage;
    double voltage_new;
    double conductance;
    double capacitance;
    double charge;
    double yt[3];
    double fy[3];
} node;

typedef struct device {
    int type;
    int n1, n2;
    double value;
} device;

node nodes[MAX_NODES];
device devices[MAX_DEVICES];

void simulate(double delta_t, double end_time, int num_nodes, int num_devices) {
    int i, j, iters;
    double t;
    double sum_conductance;
    double sum_capacitance;
    double I;

    // Print the circuit details
    printf("Circuit details: Num nodes = %d, Num devices = %d\n", num_nodes, num_devices);
    for (i = 0; i < num_devices; i++) {
        printf("Device %d: Type = %d, Nodes = %d %d, Value = %lf\n", i, devices[i].type, devices[i].n1, devices[i].n2, devices[i].value);
    }

    // Initialize the simulation
    for (i = 0; i < num_nodes; i++) {
        nodes[i].voltage = 0.0;
        nodes[i].voltage_new = 0.0;
        nodes[i].charge = 0.0;
        nodes[i].yt[0] = 0.0;
        nodes[i].yt[1] = 0.0;
        nodes[i].yt[2] = 0.0;
        nodes[i].fy[0] = 0.0;
        nodes[i].fy[1] = 0.0;
        nodes[i].fy[2] = 0.0;
    }

    // Run the simulation
    sum_conductance = 0.0;
    sum_capacitance = 0.0;
    for (i = 0; i < num_devices; i++) {
        if (devices[i].type == 0) {
            // Resistor
            sum_conductance += 1.0/devices[i].value;
        } else if (devices[i].type == 1) {
            // Capacitor
            sum_capacitance += devices[i].value;
        } else if (devices[i].type == 2) {
            // Voltage Source
            nodes[devices[i].n1].voltage_new = devices[i].value;
            nodes[devices[i].n2].voltage_new = -devices[i].value;
        }
    }
    for (i = 0; i < num_nodes; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%lf", nodes[i].voltage);
    }
    printf("\n");

    for (t = 0.0; t < end_time; t += delta_t) {
        iters = 0;
        I = 0.0;
        while (1) {
            // Update the conductances, charges, and currents
            for (i = 0; i < num_nodes; i++) {
                nodes[i].conductance = sum_conductance;
                nodes[i].capacitance = sum_capacitance;
                nodes[i].charge = 0.0;
                for (j = 0; j < num_devices; j++) {
                    if (devices[j].type == 0) {
                        // Resistor
                        if (devices[j].n1 == i) {
                            nodes[i].conductance += 1.0/devices[j].value;
                        } else if (devices[j].n2 == i) {
                            nodes[i].conductance += 1.0/devices[j].value;
                        }
                    } else if (devices[j].type == 1) {
                        // Capacitor
                        if (devices[j].n1 == i) {
                            nodes[i].capacitance += devices[j].value/delta_t;
                            nodes[i].charge -= devices[j].value*(nodes[i].voltage_new - nodes[i].voltage)/delta_t;
                        } else if (devices[j].n2 == i) {
                            nodes[i].capacitance += devices[j].value/delta_t;
                            nodes[i].charge += devices[j].value*(nodes[i].voltage_new - nodes[i].voltage)/delta_t;
                        }
                    } else if (devices[j].type == 2) {
                        // Voltage Source
                        if (devices[j].n1 == i) {
                            nodes[i].conductance = 0.0;
                            nodes[i].capacitance = 0.0;
                            nodes[i].charge = 0.0;
                        } else if (devices[j].n2 == i) {
                            nodes[i].conductance = 0.0;
                            nodes[i].capacitance = 0.0;
                            nodes[i].charge = 0.0;
                        }
                    }
                }
            }

            // Calculate the matrix coefficients
            for (i = 0; i < num_nodes; i++) {
                nodes[i].yt[0] = nodes[i].capacitance/delta_t + nodes[i].conductance;
                nodes[i].yt[1] = -nodes[i].conductance;
                nodes[i].yt[2] = -nodes[i].capacitance/delta_t;
                nodes[i].fy[0] = nodes[i].charge - nodes[i].capacitance*nodes[i].voltage/delta_t;
                nodes[i].fy[1] = -nodes[i].voltage;
                nodes[i].fy[2] = nodes[i].capacitance*nodes[i].voltage_new/delta_t;
            }

            // Solve the matrix equation
            for (i = 0; i < num_nodes-1; i++) {
                for (j = i+1; j < num_nodes; j++) {
                    double factor = nodes[i].yt[0]/nodes[j].yt[0];
                    nodes[j].yt[1] += factor*nodes[i].yt[1];
                    nodes[j].yt[2] += factor*nodes[i].yt[2];
                    nodes[j].fy[0] += factor*nodes[i].fy[0];
                    nodes[j].fy[1] += factor*nodes[i].fy[1];
                    nodes[j].fy[2] += factor*nodes[i].fy[2];
                }
            }
            nodes[num_nodes-1].voltage_new = (nodes[num_nodes-1].fy[0] - nodes[num_nodes-1].yt[1]*nodes[num_nodes-2].voltage_new)/nodes[num_nodes-1].yt[0];
            for (i = num_nodes-2; i >= 0; i--) {
                nodes[i].voltage_new = (nodes[i].fy[0] - nodes[i].yt[2]*nodes[i+1].voltage_new - nodes[i].yt[1]*nodes[i-1].voltage_new)/nodes[i].yt[0];
            }

            // Check if the voltages have converged
            double max_diff = 0.0;
            for (i = 0; i < num_nodes; i++) {
                double diff = fabs(nodes[i].voltage_new - nodes[i].voltage);
                if (diff > max_diff) {
                    max_diff = diff;
                }
            }
            if (max_diff < 1e-9) {
                break;
            }

            // Update the voltages for the next iteration
            for (i = 0; i < num_nodes; i++) {
                nodes[i].voltage = nodes[i].voltage_new;
            }

            iters++;
            if (iters > 10000) {
                printf("Simulation failed to converge!\n");
                return;
            }
        }

        // Print the currents
        I = (nodes[num_nodes-2].voltage_new - nodes[num_nodes-1].voltage_new)*sum_conductance;
        for (i = 0; i < num_devices; i++) {
            if (devices[i].type == 0) {
                printf("Device %d: Current = %lf\n", i, (nodes[devices[i].n1].voltage_new - nodes[devices[i].n2].voltage_new)/devices[i].value);
            } else if (devices[i].type == 1) {
                printf("Device %d: Current = %lf\n", i, I);
            } else if (devices[i].type == 2) {
                printf("Device %d: Current = %lf\n", i, I);
            }
        }
    }
}

int main() {
    int num_nodes, num_devices;
    int i;

    // Initialize the nodes
    num_nodes = 4;
    for (i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
    }

    // Initialize the devices
    num_devices = 3;
    devices[0].type = 0;
    devices[0].n1 = 0;
    devices[0].n2 = 1;
    devices[0].value = 1000.0;

    devices[1].type = 1;
    devices[1].n1 = 1;
    devices[1].n2 = 2;
    devices[1].value = 1e-6;

    devices[2].type = 2;
    devices[2].n1 = 2;
    devices[2].n2 = 3;
    devices[2].value = 10.0;

    // Simulate the circuit
    simulate(1e-6, 1.0, num_nodes, num_devices);

    return 0;
}
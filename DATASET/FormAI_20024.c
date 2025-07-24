//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define MAX_NODES 5
#define MAX_DEVICES 3

typedef struct device {
    char type;
    int nodes[2];
    double value;
} Device;

int num_devices;
Device devices[MAX_DEVICES];

// Function to calculate V_i - V_j based on two node voltages
double delta(int i, int j, double voltages[]) {
    return (isnan(voltages[i]) || isnan(voltages[j])) ? NAN : voltages[i] - voltages[j];
}

int main() {
    // Initialize circuit devices
    devices[0].type = 'R';
    devices[0].nodes[0] = 1;
    devices[0].nodes[1] = 2;
    devices[0].value = 100.0;

    devices[1].type = 'R';
    devices[1].nodes[0] = 2;
    devices[1].nodes[1] = 3;
    devices[1].value = 50.0;

    devices[2].type = 'V';
    devices[2].nodes[0] = 1;
    devices[2].nodes[1] = 3;
    devices[2].value = 10.0;

    num_devices = 3;

    double voltages[MAX_NODES] = { 0.0 };
    voltages[0] = 0.0; // Ground node

    // Apply Kirchhoff's laws to solve for unknown node voltages
    while (1) {
        double delta_v[MAX_DEVICES] = { 0.0 };

        for (int i = 0; i < num_devices; i++) {
            Device dev = devices[i];

            if (dev.type == 'R') {
                double delta_v_r = delta(dev.nodes[0], dev.nodes[1], voltages) / dev.value;
                delta_v[i] = delta_v_r;

                voltages[dev.nodes[0]] -= delta_v_r;
                voltages[dev.nodes[1]] += delta_v_r;
            } else if (dev.type == 'V') {
                double delta_v_v = dev.value;
                delta_v[i] = delta_v_v;

                voltages[dev.nodes[1]] -= delta_v_v;
                voltages[dev.nodes[0]] += delta_v_v;
            }
        }

        // Check for convergence
        double delta_v_sum = 0.0;
        for (int i = 0; i < num_devices; i++) {
            delta_v_sum += fabs(delta_v[i]);
        }

        if (delta_v_sum < 1e-6) {
            break;
        }
    }

    // Output results
    for (int i = 0; i < MAX_NODES; i++) {
        printf("Node %d: %.3f V\n", i, voltages[i]);
    }

    return 0;
}
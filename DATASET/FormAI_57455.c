//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DEVICES 50
#define MAX_NODES 100

// structure to represent a device
typedef struct {
    char type[10];
    int node[2];
    float value;
} device_t;

// structure to represent a node
typedef struct {
    int num;
    int devices[MAX_DEVICES];
    int num_devices;
} node_t;

// circuit simulation function
void simulate_circuit(node_t *nodes, device_t *devices, int num_nodes, int num_devices) {
    int i, j, k;
    float conductance, current, voltage, power;
    node_t *node1, *node2;

    // initialize conductance matrix
    float G[num_nodes][num_nodes];
    memset(G, 0, sizeof(G));

    // initialize current matrix
    float I[num_nodes];
    memset(I, 0, sizeof(I));

    // fill conductance and current matrices based on device values
    for (i = 0; i < num_devices; i++) {
        device_t *dev = &devices[i];
        node1 = &nodes[dev->node[0]];
        node2 = &nodes[dev->node[1]];
        conductance = 1.0 / dev->value;
        G[node1->num][node1->num] += conductance;
        G[node2->num][node2->num] += conductance;
        G[node1->num][node2->num] -= conductance;
        G[node2->num][node1->num] -= conductance;
        if (strcmp(dev->type, "V") == 0) {
            current = dev->value;
            I[node1->num] += current;
            I[node2->num] -= current;
        } else if (strcmp(dev->type, "R") == 0) {
            voltage = nodes[node1->num].num - nodes[node2->num].num;
            current = voltage / dev->value;
            I[node1->num] -= current;
            I[node2->num] += current;
        }
    }

    // print conductance and current matrices
    printf("Conductance Matrix:\n");
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            printf("%7.2f ", G[i][j]);
        }
        printf("\n");
    }
    printf("Current Matrix:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%7.2f\n", I[i]);
    }

    // solve for node voltages
    float V[num_nodes];
    memset(V, 0, sizeof(V));
    for (k = 0; k < num_nodes; k++) {
        for (i = k + 1; i < num_nodes; i++) {
            float factor = G[i][k] / G[k][k];
            for (j = k + 1; j < num_nodes; j++) {
                G[i][j] -= factor * G[k][j];
            }
            I[i] -= factor * I[k];
        }
    }
    for (i = num_nodes - 1; i >= 0; i--) {
        float sum = 0.0;
        for (j = i + 1; j < num_nodes; j++) {
            sum += G[i][j] * V[j];
        }
        V[i] = (I[i] - sum) / G[i][i];
    }

    // print node voltages
    printf("Node Voltages:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("V%d = %7.2f\n", nodes[i].num, V[i]);
    }

    // calculate power dissipation for each device
    for (i = 0; i < num_devices; i++) {
        device_t *dev = &devices[i];
        node1 = &nodes[dev->node[0]];
        node2 = &nodes[dev->node[1]];
        voltage = V[node1->num] - V[node2->num];
        power = voltage * voltage / dev->value;
        printf("%s%d: Power Dissipation = %7.2f\n", dev->type, i, power);
    }
}

int main() {
    node_t nodes[MAX_NODES];
    device_t devices[MAX_DEVICES];
    int num_nodes = 0;
    int num_devices = 0;

    // add some devices to the circuit
    devices[num_devices].value = 1e3;
    devices[num_devices].node[0] = 0;
    devices[num_devices].node[1] = 1;
    strcpy(devices[num_devices].type, "R");
    num_devices++;

    devices[num_devices].value = 5;
    devices[num_devices].node[0] = 1;
    devices[num_devices].node[1] = 2;
    strcpy(devices[num_devices].type, "V");
    num_devices++;

    devices[num_devices].value = 2e-3;
    devices[num_devices].node[0] = 2;
    devices[num_devices].node[1] = 0;
    strcpy(devices[num_devices].type, "R");
    num_devices++;

    // add nodes to the circuit
    nodes[num_nodes].num = num_nodes;
    num_nodes++;
    nodes[num_nodes].num = num_nodes;
    num_nodes++;
    nodes[num_nodes].num = num_nodes;
    num_nodes++;

    // connect devices to nodes
    for (int i = 0; i < num_devices; i++) {
        device_t *dev = &devices[i];
        node_t *node1 = &nodes[dev->node[0]];
        node_t *node2 = &nodes[dev->node[1]];
        node1->devices[node1->num_devices] = i;
        node1->num_devices++;
        node2->devices[node2->num_devices] = i;
        node2->num_devices++;
    }

    // simulate the circuit
    simulate_circuit(nodes, devices, num_nodes, num_devices);

    return 0;
}
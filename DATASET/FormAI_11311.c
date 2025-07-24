//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_NODES 100

int num_nodes = 0;

struct circuit_node {
    int node_id;
    double voltage;
    double current;
    double resistance;
};

struct circuit_node nodes[MAX_NODES];

void add_node(double voltage, double current, double resistance) {
    struct circuit_node node;
    node.node_id = num_nodes++;
    node.voltage = voltage;
    node.current = current;
    node.resistance = resistance;
    nodes[node.node_id] = node;
}

double calculate_voltage_drop(int start_node, int end_node) {
    double start_voltage = nodes[start_node].voltage;
    double end_voltage = nodes[end_node].voltage;
    double total_resistance = 0;
    for (int i = start_node; i < end_node; i++) {
        total_resistance += nodes[i].resistance;
    }
    double current = (start_voltage - end_voltage) / total_resistance;
    for (int i = start_node; i < end_node; i++) {
        nodes[i].current = current;
    }
    return start_voltage - current * nodes[start_node].resistance;
}

int main() {
    add_node(10, 0, 1);
    add_node(0, 0, 2);
    add_node(0, 0, 3);
    double voltage_drop = calculate_voltage_drop(0, 3);
    printf("Voltage drop: %fV\n", voltage_drop);
    for (int i = 0; i < num_nodes; i++) {
        printf("Node: %d, Voltage: %fV, Current: %fA, Resistance: %fOhms\n", 
            nodes[i].node_id, nodes[i].voltage, nodes[i].current, nodes[i].resistance);
    }
    return 0;
}
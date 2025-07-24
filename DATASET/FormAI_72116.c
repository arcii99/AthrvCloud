//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_EDGES 40

typedef struct edge {
    int node1;
    int node2;
    int resistance;
} Edge;

typedef struct node {
    int voltage;
    int edges[MAX_EDGES];
    int num_edges;
} Node;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(int voltage) {
    nodes[num_nodes].voltage = voltage;
    nodes[num_nodes].num_edges = 0;
    num_nodes++;
}

void add_edge(int node1, int node2, int resistance) {
    edges[num_edges].node1 = node1;
    edges[num_edges].node2 = node2;
    edges[num_edges].resistance = resistance;
    nodes[node1].edges[nodes[node1].num_edges] = num_edges;
    nodes[node1].num_edges++;
    nodes[node2].edges[nodes[node2].num_edges] = num_edges;
    nodes[node2].num_edges++;
    num_edges++;
}

void update_voltage(int node, int new_voltage) {
    int old_voltage = nodes[node].voltage;
    nodes[node].voltage = new_voltage;
    
    for (int i = 0; i < nodes[node].num_edges; i++) {
        Edge edge = edges[nodes[node].edges[i]];
        int other_node = edge.node1 == node ? edge.node2 : edge.node1;
        int resistance = edge.resistance;
        int voltage_diff = nodes[other_node].voltage - old_voltage;
        int current = voltage_diff / resistance;
        update_voltage(other_node, nodes[other_node].voltage - current * resistance);
    }
}

int main() {
    add_node(5);
    add_node(0);
    add_node(0);
    add_node(0);
    add_edge(0, 1, 1);
    add_edge(0, 2, 2);
    add_edge(1, 2, 3);
    add_edge(1, 3, 4);
    add_edge(2, 3, 5);
    
    update_voltage(0, 10);
    
    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, nodes[i].voltage);
    }
    
    return 0;
}
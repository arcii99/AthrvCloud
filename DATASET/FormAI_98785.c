//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>

#define MAX_NODES 5
#define MAX_EDGES 7

typedef struct {
    int node_id;
    int voltage;
    int connected_edges[MAX_EDGES];
} Node;

typedef struct {
    int edge_id;
    int resistance;
    int node1;
    int node2;
} Edge;

typedef struct {
    int num_nodes;
    int num_edges;
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
} Circuit;

void initialize_circuit(Circuit* circuit) {
    circuit->num_nodes = 0;
    circuit->num_edges = 0;
}

void add_node(Circuit* circuit, int voltage) {
    if (circuit->num_nodes >= MAX_NODES) {
        printf("Error: Circuit is full, cannot add more nodes\n");
        return;
    }

    Node* new_node = &circuit->nodes[circuit->num_nodes];

    new_node->node_id = circuit->num_nodes;
    new_node->voltage = voltage;

    circuit->num_nodes++;
}

void add_edge(Circuit* circuit, int resistance, int node1, int node2) {
    if (circuit->num_edges >= MAX_EDGES) {
        printf("Error: Circuit is full, cannot add more edges\n");
        return;
    }

    Edge* new_edge = &circuit->edges[circuit->num_edges];

    new_edge->edge_id = circuit->num_edges;
    new_edge->resistance = resistance;
    new_edge->node1 = node1;
    new_edge->node2 = node2;

    // Add the edge to the connected edges list for each node
    circuit->nodes[node1].connected_edges[circuit->nodes[node1].node_id] = circuit->num_edges;
    circuit->nodes[node2].connected_edges[circuit->nodes[node2].node_id] = circuit->num_edges;

    circuit->num_edges++;
}

int main() {
    Circuit circuit;
    initialize_circuit(&circuit);

    // Add nodes to the circuit
    add_node(&circuit, 5);
    add_node(&circuit, 0);

    // Add edges to the circuit
    add_edge(&circuit, 10, 0, 1);

    // Print out the circuit's nodes and edges
    printf("Circuit Nodes:\n");
    for (int i = 0; i < circuit.num_nodes; i++) {
        Node node = circuit.nodes[i];
        printf("Node ID: %d  Voltage: %d  Connected Edges:", node.node_id, node.voltage);
        for (int j = 0; j < MAX_EDGES; j++) {
            if (node.connected_edges[j] != -1) {
                printf(" %d", node.connected_edges[j]);
            }
        }
        printf("\n");
    }

    printf("Circuit Edges:\n");
    for (int i = 0; i < circuit.num_edges; i++) {
        Edge edge = circuit.edges[i];
        printf("Edge ID: %d  Resistance: %d  Node 1: %d  Node 2: %d\n", edge.edge_id, edge.resistance, edge.node1, edge.node2);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 20

// Structure to represent an edge
typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

// Structure to represent a node
typedef struct Node {
    int voltage;
    int curr;
    int outedges[MAX_EDGES];
    int inedges[MAX_EDGES];
    int num_outedges;
    int num_inedges;
} Node;

// Function to initialize the nodes and edges
void initialize(Node *nodes, Edge *edges, int n, int m) {
    for(int i=0; i<n; i++) {
        nodes[i].voltage = 0;
        nodes[i].curr = 0;
        nodes[i].num_outedges = 0;
        nodes[i].num_inedges = 0;
    }
    for(int i=0; i<m; i++) {
        edges[i].from = 0;
        edges[i].to = 0;
        edges[i].weight = 0;
    }
}

// Function to add an edge to the graph
void add_edge(Node *nodes, Edge *edges, int u, int v, int w) {
    Edge e;
    e.from = u;
    e.to = v;
    e.weight = w;
    edges[nodes[u].num_outedges] = e;
    nodes[u].outedges[nodes[u].num_outedges++] = v;
    nodes[v].inedges[nodes[v].num_inedges++] = u;
}

// Function to simulate the circuit for a given time
void simulate_circuit(Node *nodes, Edge *edges, int n, int m, int time) {
    for(int t=0; t<time; t++) {
        // Compute the currents flowing through each edge
        for(int i=0; i<m; i++) {
            int u = edges[i].from;
            int v = edges[i].to;
            int w = edges[i].weight;
            int i_uv = (nodes[u].voltage - nodes[v].voltage) / w;
            int i_vu = -i_uv;
            nodes[u].curr += i_uv;
            nodes[v].curr += i_vu;
        }
        // Update the voltages of each node based on the currents
        for(int i=0; i<n; i++) {
            int i_in = 0;
            for(int j=0; j<nodes[i].num_inedges; j++) {
                int u = nodes[i].inedges[j];
                i_in += nodes[u].curr;
            }
            int i_out = 0;
            for(int j=0; j<nodes[i].num_outedges; j++) {
                int v = nodes[i].outedges[j];
                i_out += nodes[v].curr;
            }
            nodes[i].voltage += i_in - i_out;
            nodes[i].curr = 0;
        }
        // Print the state of the circuit at each time step
        printf("Time %d:\n", t+1);
        for(int i=0; i<n; i++) {
            printf("Node %d - Voltage: %d\n", i+1, nodes[i].voltage);
        }
        printf("\n");
    }
}

int main() {
    // Sample circuit with 3 nodes and 3 edges
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];
    initialize(nodes, edges, 3, 3);
    add_edge(nodes, edges, 0, 1, 1);
    add_edge(nodes, edges, 1, 2, 2);
    add_edge(nodes, edges, 2, 0, 3);
    simulate_circuit(nodes, edges, 3, 3, 5);
    return 0;
}
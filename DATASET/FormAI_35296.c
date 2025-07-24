//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct node {
    int id;
    int neighbors[MAX_NODES];
    int n_neighbors;
} node;

node nodes[MAX_NODES];

void add_node(int id) {
    if (id < MAX_NODES) {
        nodes[id].id = id;
        nodes[id].n_neighbors = 0;
    }
}

void add_edge(int n1, int n2) {
    if (n1 < MAX_NODES && n2 < MAX_NODES) {
        nodes[n1].neighbors[nodes[n1].n_neighbors++] = n2;
        nodes[n2].neighbors[nodes[n2].n_neighbors++] = n1;
    }
}

void print_topology() {
    printf("Network Topology Map:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (nodes[i].id != -1) {
            printf("Node %d: ", nodes[i].id);
            for (int j = 0; j < nodes[i].n_neighbors; j++) {
                printf("%d ", nodes[i].neighbors[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    // Let's add some nodes and edges
    add_node(0);
    add_node(1);
    add_node(2);
    add_node(3);
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 0);
    add_edge(0, 2);
    add_edge(1, 3);
    
    // Print the topology map
    print_topology();
    
    return 0;
}
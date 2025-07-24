//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

struct node {
    int id;
    char label[20];
    int neighbors[MAX_NODES];
} graph[MAX_NODES];

int num_nodes = 0;

void add_node(char label[]) {
    struct node new_node;
    new_node.id = num_nodes;
    strcpy(new_node.label, label);

    for (int i=0; i<MAX_NODES; i++) {
        new_node.neighbors[i] = -1;
    }

    graph[num_nodes++] = new_node;
}

void add_edge(int u, int v) {
    graph[u].neighbors[v] = 1;
    graph[v].neighbors[u] = 1;
}

void print_graph() {
    printf("Network Topology Mapper\n");
    printf("=======================\n\n");

    for (int i=0; i<num_nodes; i++) {
        printf("Node[%d] (%s) connected to: ", graph[i].id, graph[i].label);

        for (int j=0; j<MAX_NODES; j++) {
            if (graph[i].neighbors[j] == 1) {
                printf("%d ", j);
            }
        }

        printf("\n");
    }
}

int main() {
    // Add some nodes
    add_node("Server 1");
    add_node("Switch");
    add_node("Router");
    add_node("Server 2");

    // Add some edges
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(0, 3);

    // Print the graph
    print_graph();

    return 0;
}
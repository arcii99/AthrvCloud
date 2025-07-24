//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct node {
    int id;
    int connected[MAX_NODES];
    int num_connections;
};

void new_node(struct node *graph, int node_id, int *num_nodes) {
    graph[*num_nodes].id = node_id;
    graph[*num_nodes].num_connections = 0;
    *num_nodes += 1;
}

void connect(struct node *graph, int node1, int node2) {
    graph[node1].connected[graph[node1].num_connections] = node2;
    graph[node2].connected[graph[node2].num_connections] = node1;
    graph[node1].num_connections++;
    graph[node2].num_connections++;
}

void print_graph(struct node *graph, int num_nodes) {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d is connected to: ", graph[i].id);
        for (int j = 0; j < graph[i].num_connections; j++) {
            printf("%d ", graph[i].connected[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_nodes = 0;
    struct node graph[MAX_NODES];

    new_node(graph, 1, &num_nodes);
    new_node(graph, 2, &num_nodes);
    new_node(graph, 3, &num_nodes);
    new_node(graph, 4, &num_nodes);
    new_node(graph, 5, &num_nodes);
    new_node(graph, 6, &num_nodes);

    connect(graph, 0, 1);
    connect(graph, 1, 2);
    connect(graph, 1, 3);
    connect(graph, 4, 5);
    connect(graph, 2, 4);
    connect(graph, 3, 4);
    connect(graph, 2, 5);
    connect(graph, 1, 5);

    print_graph(graph, num_nodes);

    return 0;
}
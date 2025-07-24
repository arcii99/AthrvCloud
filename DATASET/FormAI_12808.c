//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int num_nodes;
    struct Edge edges[MAX_NODES];
    int adjacency_matrix[MAX_NODES][MAX_NODES];
};

void add_edge(struct Graph *graph, int source, int destination, int weight) {
    graph->adjacency_matrix[source][destination] = weight;
    graph->edges[graph->num_nodes].source = source;
    graph->edges[graph->num_nodes].destination = destination;
    graph->edges[graph->num_nodes].weight = weight;
    graph->num_nodes++;
}

void print_graph(struct Graph *graph) {
    int i, j;
    for (i = 0; i < graph->num_nodes; i++) {
        for (j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->num_nodes = 0;
    int num_edges = 7;
    add_edge(graph, 0, 1, 5);
    add_edge(graph, 0, 2, 4);
    add_edge(graph, 1, 2, 2);
    add_edge(graph, 1, 3, 6);
    add_edge(graph, 2, 3, 3);
    add_edge(graph, 2, 4, 4);
    add_edge(graph, 3, 4, 5);
    print_graph(graph);
    free(graph);
    return 0;
}
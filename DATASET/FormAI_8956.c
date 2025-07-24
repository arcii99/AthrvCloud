//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

#define MAX_VERTICES 20

struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

void init_graph(struct Graph* graph) {

    graph->num_vertices = 0;

    for(int i = 0; i < MAX_VERTICES; i++) {
        for(int j = 0; j < MAX_VERTICES; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(struct Graph* graph, int src, int dst) {
    graph->adj_matrix[src][dst] = 1;
    graph->adj_matrix[dst][src] = 1;
}

void print_graph(struct Graph* graph) {
    for(int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        for(int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph graph;
    init_graph(&graph);

    graph.num_vertices = 6;

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);

    print_graph(&graph);

    return 0;
}
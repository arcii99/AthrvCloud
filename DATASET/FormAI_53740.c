//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>

#define MAX_VERTICES 100

// Graph data structure
typedef struct Graph {
    int num_vertices, num_edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize graph
void init_graph(Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

// Add edge to graph
void add_edge(Graph *graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->num_edges++;
}

// Print graph
void print_graph(Graph *graph) {
    printf("Number of vertices: %d, Number of edges: %d\n", graph->num_vertices, graph->num_edges);
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    int num_vertices = 5;

    init_graph(&graph, num_vertices);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 4);

    print_graph(&graph);

    return 0;
}
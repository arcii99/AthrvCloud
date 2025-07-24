//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int num_vertices;
    int** adj_matrix;
};

// Function to create and return a graph
struct Graph* create_graph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    // allocate memory for adjacency matrix
    graph->adj_matrix = (int**) malloc(num_vertices * sizeof(int*));
    for(int i = 0; i < num_vertices; i++) {
        graph->adj_matrix[i] = (int*) malloc(num_vertices * sizeof(int));
        for(int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the given graph
void add_edge(struct Graph* graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    graph->adj_matrix[dest][src] = 1;
}

// Function to print the graph
void print_graph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        for(int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_vertices = 5;
    struct Graph* graph = create_graph(num_vertices);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 0);
    print_graph(graph);

    return 0;
}
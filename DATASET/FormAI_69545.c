//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#define MAX 100

// Define graph structure
typedef struct Graph {
    int edges[MAX][MAX];
    int num_vertices;
} Graph;

// Function to add edges between vertices
void add_edge(Graph *graph, int source, int destination) {
    graph->edges[source][destination] = 1;
}

// Function to initialize graph
void initialize_graph(Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
}

// Function to print the graph
void print_graph(Graph *graph) {
    printf("Graph:\n");
    int i, j;
    for (i = 0; i < graph->num_vertices; i++) {
        for (j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    initialize_graph(&graph, 5);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 4);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);
    print_graph(&graph);
    return 0;
}
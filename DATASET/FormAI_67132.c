//FormAI DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph data structure
struct Graph {
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize graph
void init_graph(struct Graph *g, int num_vertices) {
    g->num_vertices = num_vertices;
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            g->adjacency_matrix[i][j] = 0;
        }
    }
}

// Function to add edge to graph
void add_edge(struct Graph *g, int u, int v) {
    g->adjacency_matrix[u][v] = 1;    
    g->adjacency_matrix[v][u] = 1;
}

// Function to print the graph
void print_graph(struct Graph *g) {
    int i, j;
    for (i = 0; i < g->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (j = 0; j < g->num_vertices; j++) {
            if (g->adjacency_matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    struct Graph g;
    init_graph(&g, 6);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    add_edge(&g, 4, 5);
    print_graph(&g);
    return 0;
}
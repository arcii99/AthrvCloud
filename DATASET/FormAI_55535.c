//FormAI DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

void init_graph(Graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph* g, int src, int dest, int weight) {
    g->adj_matrix[src][dest] = weight;
    g->adj_matrix[dest][src] = weight;
}

void print_graph(Graph* g) {
    printf("Adjacency matrix:\n");
    for(int i = 0; i < g->num_vertices; i++) {
        for(int j = 0; j< g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g, 6); // create graph with 6 vertices
    add_edge(&g, 0, 1, 1); // add edge from vertex 0 to vertex 1 with weight 1
    add_edge(&g, 1, 2, 2); // add edge from vertex 1 to vertex 2 with weight 2
    add_edge(&g, 2, 3, 3); // add edge from vertex 2 to vertex 3 with weight 3
    add_edge(&g, 3, 0, 4); // add edge from vertex 3 to vertex 0 with weight 4
    add_edge(&g, 4, 1, 5); // add edge from vertex 4 to vertex 1 with weight 5
    add_edge(&g, 5, 3, 6); // add edge from vertex 5 to vertex 3 with weight 6
    
    print_graph(&g);
    
    return 0;
}
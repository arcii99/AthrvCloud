//FormAI DATASET v1.0 Category: Graph representation ; Style: unmistakable
#include <stdio.h>

#define MAX_VERTICES 10

// Graph Struct
typedef struct {
    int n;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize Graph
void initialize_graph(Graph *g) 
{
    int i, j;
    g -> n = 0;
    for (i = 0; i < MAX_VERTICES; i++)
        for (j = 0; j < MAX_VERTICES; j++)
            g -> adjacency_matrix[i][j] = 0;
}

// Add Edge
void add_edge(Graph *g, int u, int v) 
{
    g -> adjacency_matrix[u][v] = 1;
}

// Print Graph
void print_graph(Graph *g)
{
    int i, j;
    for (i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->n; j++)
            printf("%d ", g->adjacency_matrix[i][j]);
        printf("\n");
    }
}

// Main Method
int main() 
{
    Graph g;
    initialize_graph(&g);
    
    g.n = 6;
    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    add_edge(&g, 4, 0);
    add_edge(&g, 4, 1);
    add_edge(&g, 4, 5);
    
    printf("Graph Connections: \n");
    print_graph(&g);
    
    return 0;
}
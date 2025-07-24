//FormAI DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int v1, v2;
    int weight;
} Edge;

typedef struct {
    int n; 
    int m; 
    Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph* G, int num_v, int num_e) {
    G->n = num_v;
    G->m = num_e;
}

int main() {
    Graph G;
    int n = 5;
    int m = 7;
    init_graph(&G, n, m);
    
    // add edges to the graph
    G.edges[0].v1 = 0;
    G.edges[0].v2 = 1;
    G.edges[0].weight = 5;
    
    G.edges[1].v1 = 0;
    G.edges[1].v2 = 2;
    G.edges[1].weight = 3;
    
    G.edges[2].v1 = 0;
    G.edges[2].v2 = 4;
    G.edges[2].weight = 4;
    
    G.edges[3].v1 = 1;
    G.edges[3].v2 = 3;
    G.edges[3].weight = 2;
    
    G.edges[4].v1 = 2;
    G.edges[4].v2 = 1;
    G.edges[4].weight = 6;
    
    G.edges[5].v1 = 3;
    G.edges[5].v2 = 0;
    G.edges[5].weight = 1;
    
    G.edges[6].v1 = 4;
    G.edges[6].v2 = 3;
    G.edges[6].weight = 5;
    
    // print edges
    printf("Edges:\n");
    for (int i = 0; i < m; i++) {
        printf("(%d, %d) weight=%d\n", G.edges[i].v1, G.edges[i].v2, G.edges[i].weight);
    }
    
    // print adjacency matrix
    int adj_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int i = 0; i < m; i++) {
        int v1 = G.edges[i].v1;
        int v2 = G.edges[i].v2;
        adj_matrix[v1][v2] = G.edges[i].weight;
    }
    
    printf("\nAdjacency Matrix:\n    ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n   ");
    for (int i = 0; i < n * 2; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d | ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
    int v, w;
} Edge;

Edge edges[MAX_EDGES]; // list of edges
int degree[MAX_VERTICES] = {0}; // degree of each vertex
int V = 0, E = 0; // number of vertices and edges

void addEdge(int v, int w) {
    edges[E++] = (Edge) {v, w};
    degree[v]++; degree[w]++;
}

void printGraph() {
    printf("Graph:\n");
    for (int i = 0; i < V; i++) {
        printf("%d:", i);
        for (int j = 0; j < E; j++) {
            if (edges[j].v == i || edges[j].w == i) {
                printf(" %d", edges[j].v == i ? edges[j].w : edges[j].v);
            }
        }
        printf("\n");
    }
}

int main() {
    // add some edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);
    addEdge(0, 2);
    
    V = 4; // set number of vertices
    
    printGraph();
    
    return 0;
}
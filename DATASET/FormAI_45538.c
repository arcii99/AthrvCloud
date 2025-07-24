//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10

typedef struct{
    int edges[MAX_NODES][MAX_NODES];
    int n; // number of nodes
    int e; // number of edges
}Graph;

void createGraph(Graph* g) {
    int i, j;
    g->n = 0;
    g->e = 0;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            g->edges[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        printf("Invalid nodes\n");
        return;
    }
    g->edges[u][v] = 1;
    g->e++;
}

void printGraph(Graph* g) {
    int i, j;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    createGraph(&g);
    g.n = 5; // adding 5 nodes

    addEdge(&g, 0, 1); // adding an edge from 0 to 1
    addEdge(&g, 0, 2); // adding an edge from 0 to 2
    addEdge(&g, 1, 2); // adding an edge from 1 to 2

    printGraph(&g); // printing the graph

    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 50

typedef struct Graph {
    int numVertices;
    int numEdges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init(Graph *g) {
    g->numVertices = 0;
    g->numEdges = 0;
    memset(g->adjMatrix, 0, sizeof(g->adjMatrix));
}

void addEdge(Graph *g, int u, int v) {
    if (u < 0 || u >= g->numVertices || v < 0 || v >= g->numVertices) {
        printf("Invalid vertices\n");
        return;
    }

    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
    g->numEdges++;
}

void removeEdge(Graph *g, int u, int v) {
    if (u < 0 || u >= g->numVertices || v < 0 || v >= g->numVertices) {
        printf("Invalid vertices\n");
        return;
    }

    g->adjMatrix[u][v] = 0;
    g->adjMatrix[v][u] = 0;
    g->numEdges--;
}

void printGraph(Graph *g) {
    printf("Number of vertices: %d\n", g->numVertices);
    printf("Number of edges: %d\n", g->numEdges);
    printf("Adjacency matrix:\n");

    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }

        printf("\n");
    }
}

Graph* paranoidInit() {
    Graph *g = (Graph*) malloc(sizeof(Graph));

    if (!g) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    init(g);

    return g;
}

void paranoidAddEdge(Graph *g, int u, int v) {
    if (!g) {
        printf("Graph is not initialized\n");
        return;
    }

    if (u < 0 || u >= g->numVertices || v < 0 || v >= g->numVertices) {
        printf("Invalid vertices\n");
        return;
    }

    if (g->adjMatrix[u][v]) {
        printf("Edge already exists\n");
        return;
    }

    if (g->numEdges >= g->numVertices*(g->numVertices-1)/2) {
        printf("Graph is already complete, cannot add more edges\n");
        return;
    }

    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
    g->numEdges++;
}

void paranoidRemoveEdge(Graph *g, int u, int v) {
    if (!g) {
        printf("Graph is not initialized\n");
        return;
    }

    if (u < 0 || u >= g->numVertices || v < 0 || v >= g->numVertices) {
        printf("Invalid vertices\n");
        return;
    }

    if (!g->adjMatrix[u][v]) {
        printf("Edge does not exist\n");
        return;
    }

    g->adjMatrix[u][v] = 0;
    g->adjMatrix[v][u] = 0;
    g->numEdges--;
}

void paranoidPrintGraph(Graph *g) {
    if (!g) {
        printf("Graph is not initialized\n");
        return;
    }

    printf("Number of vertices: %d\n", g->numVertices);
    printf("Number of edges: %d\n", g->numEdges);
    printf("Adjacency matrix:\n");

    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

int main() {
    Graph *g = paranoidInit();

    paranoidAddEdge(g, 0, 1);
    paranoidAddEdge(g, 0, 2);
    paranoidAddEdge(g, 1, 2);
    paranoidAddEdge(g, 2, 3);
    paranoidAddEdge(g, 3, 4);

    paranoidPrintGraph(g);

    paranoidRemoveEdge(g, 1, 2);

    paranoidPrintGraph(g);

    paranoidAddEdge(g, 4, 5);

    paranoidPrintGraph(NULL);

    paranoidRemoveEdge(NULL, 2, 3);

    paranoidPrintGraph(g);

    free(g);

    return 0;
}
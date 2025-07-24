//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTICES 10

struct Graph {
    int vertices[MAX_VERTICES];
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} g;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        g.vertices[i] = i;
        for (int j = 0; j < MAX_VERTICES; j++) {
            g.adj_matrix[i][j] = 0;
        }
    }
    g.num_vertices = 0;
}

void addVertex(int v) {
    if (g.num_vertices == MAX_VERTICES) {
        printf("Error: Graph already contains max number of vertices\n");
        return;
    }
    g.vertices[g.num_vertices] = v;
    g.num_vertices++;
}

void addEdge(int v1, int v2) {
    g.adj_matrix[v1][v2] = 1;
    g.adj_matrix[v2][v1] = 1;
}

void printGraph() {
    printf("Vertices: ");
    for (int i = 0; i < g.num_vertices; i++) {
        printf("%d ", g.vertices[i]);
    }
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g.num_vertices; i++) {
        for (int j = 0; j < g.num_vertices; j++) {
            printf("%d ", g.adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeGraph();
    addVertex(1);
    addVertex(2);
    addVertex(3);
    addVertex(4);
    addVertex(5);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(2,4);

    printGraph();

    return 0;
}
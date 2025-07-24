//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices for the graph
#define MAX_VERTICES 1000

// Define the colors available for coloring the vertices
#define RED 0
#define GREEN 1
#define BLUE 2

// Define a structure to represent a graph as an adjacency matrix
typedef struct graph {
    int n; // Number of vertices in the graph
    int edges[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix for the graph
} Graph;

// Define a function to initialize the graph
void initGraph(Graph *g, int n) {
    g->n = n;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            g->edges[i][j] = 0;
        }
    }
}

// Define a function to add a new edge to the graph
void addEdge(Graph *g, int u, int v) {
    g->edges[u][v] = g->edges[v][u] = 1;
}

// Define a function to check if a vertex has been colored with a particular color
int hasColor(Graph *g, int v, int color[]) {
    int i;
    for (i = 0; i < g->n; i++) {
        if (g->edges[v][i] && color[i] == color[v]) {
            return 1;
        }
    }
    return 0;
}

// Define a function to perform graph coloring using backtracking
int colorGraph(Graph *g, int m, int color[], int v) {
    if (v == g->n) {
        return 1;
    }
    int c;
    for (c = 0; c < m; c++) {
        color[v] = c;
        if (!hasColor(g, v, color) && colorGraph(g, m, color, v + 1)) {
            return 1;
        }
    }
    color[v] = -1;
    return 0;
}

// Define the main function to create and color the graph
int main(void) {
    int n = 5; // Number of vertices in the graph
    Graph g;
    initGraph(&g, n);
    // Add edges to the graph
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    int m = 3; // Number of colors available
    int color[n];
    int i;
    for (i = 0; i < n; i++) {
        color[i] = -1;
    }
    if (colorGraph(&g, m, color, 0)) {
        printf("Graph can be colored using %d colors\n", m);
        for (i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Graph cannot be colored using %d colors\n", m);
    }
    return 0;
}
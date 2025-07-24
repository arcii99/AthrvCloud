//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the maximum number of colors to use
#define MAX_COLORS 10

// Define the graph structure
typedef struct {
    int edges[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

// Initialize the graph
void initGraph(Graph* g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->edges[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(Graph* g, int src, int dest) {
    g->edges[src][dest] = g->edges[dest][src] = 1;
}

// Determine if two vertices are adjacent in a graph
bool isAdjacent(Graph* g, int v1, int v2) {
    return g->edges[v1][v2] == 1;
}

// Greedy Graph Coloring Algorithm
void colorGraph(Graph* g, int colors[]) {
    for (int i = 0; i < g->num_vertices; i++) {
        bool used_colors[MAX_COLORS] = {};
        for (int j = 0; j < g->num_vertices; j++) {
            if (isAdjacent(g, i, j) && colors[j]) {
                used_colors[colors[j]] = true;
            }
        }
        for (int c = 1; c <= MAX_COLORS; c++) {
            if (!used_colors[c]) {
                colors[i] = c;
                break;
            }
        }
    }
}

// Print the colors of the vertices in the graph
void printColors(Graph* g, int colors[]) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: %d\n", i, colors[i]);
    }
}

// Main program
int main() {
    // Create a graph
    Graph g;
    initGraph(&g, 6);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 4, 5);

    // Color the graph
    int colors[MAX_VERTICES] = {};
    colorGraph(&g, colors);

    // Print the colors of the vertices
    printColors(&g, colors);

    return 0;
}
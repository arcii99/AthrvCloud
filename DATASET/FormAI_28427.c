//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>

#define MAX_VERTICES 1000

// Data structure for an edge in the graph
typedef struct Edge {
    int a, b;
} Edge;

// Graph data structure
typedef struct Graph {
    int V, E;
    Edge edges[MAX_VERTICES];
} Graph;

// Color array to store color of each vertex (-1 means uncolored)
int color[MAX_VERTICES];

// Function to check if it is safe to color a vertex with a given color
int isSafe(Graph *G, int vertex, int c) {
    for (int i = 0; i < G->E; i++) {
        Edge e = G->edges[i];
        if (e.a == vertex) {
            if (color[e.b] == c) {
                return 0;
            }
        } else if (e.b == vertex) {
            if (color[e.a] == c) {
                return 0;
            }
        }
    }
    return 1;
}

// Recursive function to find a valid color for a vertex
int graphColoringUtil(Graph *G, int vertex, int colors) {
    // If all vertices are colored, return 1
    if (vertex == G->V) {
        return 1;
    }
    // Try all possible colors for this vertex
    for (int c = 1; c <= colors; c++) {
        if (isSafe(G, vertex, c)) {
            color[vertex] = c;
            // Recursively color the rest of the vertices
            if (graphColoringUtil(G, vertex+1, colors)) {
                return 1;
            }
            // If coloring with this color doesn't work, backtrack
            color[vertex] = -1;
        }
    }
    return 0;
}

// Function to find a valid color for the graph
void graphColoring(Graph *G, int colors) {
    for (int i = 0; i < G->V; i++) {
        color[i] = -1;
    }
    if (graphColoringUtil(G, 0, colors)) {
        printf("The graph can be colored with at most %d colors:\n", colors);
        for (int i = 0; i < G->V; i++) {
            printf("Vertex %d => Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", colors);
    }
}

int main() {
    Graph G;
    G.V = 5;
    G.E = 6;
    G.edges[0].a = 0; G.edges[0].b = 1;
    G.edges[1].a = 0; G.edges[1].b = 2;
    G.edges[2].a = 1; G.edges[2].b = 3;
    G.edges[3].a = 2; G.edges[3].b = 3;
    G.edges[4].a = 3; G.edges[4].b = 4;
    G.edges[5].a = 4; G.edges[5].b = 0;
    graphColoring(&G, 3);
    return 0;
}
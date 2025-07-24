//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_COLORS 4

typedef struct Edge {
    int src;
    int dest;
} Edge;

int numVertices = 0;
int numEdges = 0;
Edge edges[MAX_EDGES];
int colors[MAX_VERTICES];

int isSafe(int v, int c) {
    for (int i = 0; i < numEdges; i++) {
        Edge e = edges[i];
        if (e.src == v && colors[e.dest] == c) {
            return 0;
        } else if (e.dest == v && colors[e.src] == c) {
            return 0;
        }
    }
    return 1;
}

int colorGraph(int v) {
    if (v == numVertices) {
        return 1;
    }
    
    for (int c = 1; c <= MAX_COLORS; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;
            if (colorGraph(v+1)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    
    return 0;
}

void printGraph() {
    printf("Vertices: %d\n", numVertices);
    printf("Edges: %d\n", numEdges);
    printf("Coloring:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Color %d\n", i+1, colors[i]);
    }
}

void generateGraph() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random graph
    numVertices = rand() % MAX_VERTICES + 1;
    int maxEdges = (numVertices * (numVertices - 1)) / 2;
    numEdges = rand() % MAX_EDGES + 1;
    if (numEdges > maxEdges) {
        numEdges = maxEdges;
    }
    for (int i = 0; i < numEdges; i++) {
        Edge e;
        e.src = rand() % numVertices;
        e.dest = rand() % numVertices;
        while (e.src == e.dest) {
            e.dest = rand() % numVertices;
        }
        edges[i] = e;
    }
}

int main() {
    generateGraph();
    int success = colorGraph(0);
    if (success) {
        printGraph();
    } else {
        printf("Unable to color graph.\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: safe
#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency Matrix representation of the graph
int colors[MAX_VERTICES]; // Array to store colors of each vertex
int numVertices; // Number of vertices in the graph

// A function to check if it is safe to assign color c to vertex v
int isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && colors[i] == c) {
            return 0; // if adjacent vertex has same color, then it is not safe
        }
    }
    return 1; // otherwise, it is safe
}

// Recursive function to assign colors to each vertex
void graphColoring(int vertex) {
    if (vertex == numVertices) { // all vertices are assigned colors
        printf("Solution:\n"); 
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
        return;
    }

    for (int c = 1; c <= numVertices; c++) {
        if (isSafe(vertex, c)) { // check if it is safe to assign color c to vertex
            colors[vertex] = c; // assign color c to vertex 
            graphColoring(vertex + 1); // recursively assign colors to next vertex
            colors[vertex] = 0; // backtrack to previous state
        }
    }
}

int main() {
    // initialize graph - example input
    int edges[][2] = {{0, 1}, {0, 4}, {0, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}};
    numVertices = 6;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < 9; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = graph[v][u] = 1;
    }

    // start graph coloring
    graphColoring(0);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to check if it is safe to assign a color to a vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Recursive function to assign colors to all vertices of the graph
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // If all vertices are colored, return true
    if (v == V)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is safe
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            // Recur for the next vertex
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            // Backtrack and try another color
            color[v] = 0;
        }
    }

    // If all possible color assignments for v are tried and none of them worked, return false
    return false;
}

// Function to assign colors to vertices of a graph
void graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive function with the first vertex
    if (!graphColoringUtil(graph, m, color, 0))
        printf("Solution does not exist.");
    else {
        printf("Solution exists:");
        for (int i = 0; i < V; i++)
            printf(" %d", color[i]);
    }
}

int main() {
    // Sample Graph with 4 vertices and 5 edges
    bool graph[V][V] = { { 0, 1, 1, 1 },
                         { 1, 0, 1, 0 },
                         { 1, 1, 0, 1 },
                         { 1, 0, 1, 0 } };
    int m = 3; // Number of colors

    graphColoring(graph, m);
    return 0;
}
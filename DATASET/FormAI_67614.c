//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of vertices in the graph
#define V 5

/* This function checks if the current color assignment is safe for the given vertex `v` */
bool isSafe(int graph[V][V], int color[V], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

/* This is the recursive function to solve the graph coloring problem using backtracking approach */
bool graphColorUtil(int graph[V][V], int color[V], int m, int v) {
    // base case: if all the vertices are assigned colors, return true
    if (v == V) {
        return true;
    }

    // Try different colors for the vertex `v`
    for (int c = 1; c <= m; c++) {
        // check if the current color assignment is safe for vertex `v`
        if (isSafe(graph, color, v, c)) {
            // assign color `c` to vertex `v`
            color[v] = c;

            // recur for the next vertex
            if (graphColorUtil(graph, color, m, v + 1)) {
                return true;
            }

            // backtrack
            color[v] = 0;
        }
    }
    return false;
}

/* This function solves the graph coloring problem using backtracking approach */
bool graphColoring(int graph[V][V], int m) {
    // Initialize all the vertices with the color `0`
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call recursive function `graphColorUtil()` for vertex 0
    if (!graphColorUtil(graph, color, m, 0)) {
        return false;
    }

    // the solution is found, print the solution
    printf("The graph can be colored using at most %d colors:\n", m);
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i + 1, color[i]);
    }
    return true;
}

int main() {
    // Define the graph edges
    int graph[V][V] = {
        { 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1 },
        { 1, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 0 }
    };

    // Define the number of colors available
    int m = 3;

    // Solve the graph coloring problem
    if (!graphColoring(graph, m)) {
        printf("Solution does not exist.\n");
    }
    return 0;
}
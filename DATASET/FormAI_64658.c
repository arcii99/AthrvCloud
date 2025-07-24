//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
/* C Program to solve Graph Coloring Problem using Backtracking */

#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

void printSolution(int color[]);

// Utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Function to solve Graph Coloring Problem using Backtracking
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1) == true)
                return true;
            color[v] = 0;
        }
    }

    return false;
}

// Function to solve Graph Coloring Problem using Backtracking
bool graphColoring(bool graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(color);
    return true;
}

// Utility function to print solution
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3;
    graphColoring(graph, m);
    return 0;
}
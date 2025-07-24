//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define number of vertices and edges in the graph
#define V 4
#define E 5

// Function to print the solution
void printSolution(int color[]) {
    printf("The coloring of each vertex:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

// Function to check if the vertex can be colored
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if ((graph[v][i]) && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to implement graph coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[V], int v) {
    if (v == V) {
        return 1;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1) == 1) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

// Function to solve graph coloring problem
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist.\n");
    } else {
        printSolution(color);
    }
}

// Driver program to test above functions
int main() {
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}};
    int m = 3; // Number of colors
    printf("Graph Coloring Problem Solution:\n");
    graphColoring(graph, m);
    return 0;
}
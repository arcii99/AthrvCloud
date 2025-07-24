//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 5 // number of vertices
#define COLORS 3 // number of colors

// function to check if it is safe to assign color c to vertex v
bool isSafe(int graph[V][V], int colors[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && colors[i] == c) {
            return false;
        }
    }
    return true;
}

// recursive function to solve graph coloring problem
bool graphColoringUtil(int graph[V][V], int colors[], int v) {
    // base case: if all vertices are assigned a color
    if (v == V) {
        return true;
    }

    // try all colors for vertex v
    for (int c = 1; c <= COLORS; c++) {
        // check if it is safe to assign color c to vertex v
        if (isSafe(graph, colors, v, c)) {
            colors[v] = c;
            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, colors, v+1)) {
                return true;
            }
            colors[v] = 0; // unassign color
        }
    }

    return false; // backtracking
}

// function to solve graph coloring problem
bool graphColoring(int graph[V][V]) {
    int colors[V] = {0}; // initialize all colors as unassigned

    // start with vertex 0
    if (!graphColoringUtil(graph, colors, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    // print the solution
    printf("Solution exists with the following color assignment:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }

    return true;
}

// main function to test graph coloring problem
int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    graphColoring(graph);
    return 0;
}
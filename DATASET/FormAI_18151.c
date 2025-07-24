//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // Total number of vertices

void printSolution(int color[]);
bool isSafe(bool graph[V][V], int color[V], int v, int c);

/* A utility function to check if the current color assignment is safe for vertex u */
bool isSafe(bool graph[V][V], int color[V], int v, int c)
{
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

/* A recursive utility function to solve the graph coloring problem */
bool graphColoringUtil(bool graph[V][V], int m, int color[V], int v)
{
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is safe
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }
    return false;
}

/* This function solves the graph coloring problem using Backtracking. */
void graphColoring(bool graph[V][V], int m)
{
    // Initialize all color values as 0. This indicates that no color is assigned to any vertex yet.
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist");
    }

    // Print the solution
    printSolution(color);
}

/* A utility function to print solution */
void printSolution(int color[])
{
    printf("Solution Exists: Following are the assigned colors \n");
    for (int i = 0; i < V; i++) {
        printf(" %d ", color[i]);
    }
}

/*------------------------Main Section------------------------*/
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};

    int m = 3; // Number of colors

    graphColoring(graph, m);
    printf("\n");

    return 0;
}
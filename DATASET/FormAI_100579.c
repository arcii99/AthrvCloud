//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4     // Number of vertices in the given graph

// A utility function to print solution
void printSolution(int color[]);

// A utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// A recursive utility function to solve graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    // If all vertices are assigned a color then return true
    if (v == V)
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is possible
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            // recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1) == true)
                return true;

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// main function to solve graph coloring problem
void graphColoring(bool graph[V][V], int m)
{
    int color[V];

    // Initialize all color values as 0
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive utility function
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        printf("Solution does not exist");
        return;
    }

    // Print the solution
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    printSolution(color);
}

/* A utility function to print solution */
void printSolution(int color[])
{
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, color[i]);
}

// main driver program to test above functions
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 2;  // Number of colors

    graphColoring(graph, m);
    return 0;
}
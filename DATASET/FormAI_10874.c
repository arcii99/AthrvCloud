//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7

// Function to print the solution
void printSolution(int color[])
{
    printf("Coloring of Graph-> Vertex   Color\n");
    for (int i = 0; i < V; i++)
        printf("                %d         %d\n", i, color[i]);
}

// Check if the current color assignment is valid for the given vertex 'v'
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// A recursive utility function to solve Graph Coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    // If all vertices are assigned a color, then return true
    if (v == V)
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if the assignment of color c to v is valid
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If assigning color c doesn't lead to a solution, then backtrack
            color[v] = 0;
        }
    }
    return false;
}

// This function solves the m Coloring problem using recursion
void graphColoring(bool graph[V][V], int m)
{
    // Initialize all color values as 0. This initialization is needed
    // correct functioning of isSafe()
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == false)
        printf("Sorry, there is no solution with %d colors\n", m);
    else
        printSolution(color);
}

int main()
{
    bool graph[V][V] = {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 1, 1, 0},
                        {1, 1, 0, 1, 1, 0, 1},
                        {1, 0, 1, 0, 1, 0, 1},
                        {0, 1, 1, 1, 0, 1, 1},
                        {0, 1, 0, 0, 1, 0, 1},
                        {0, 0, 1, 1, 1, 1, 0}};

    int m = 4; // Number of colors

    printf("Graph Coloring Problem ->\n\n");

    graphColoring(graph, m);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define number of vertices in the graph
#define V 4

// Function to print the solution
void printSolution(int color[])
{
    printf("Color assignments:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

// Check if it is safe to assign color c to vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Recursive function to solve graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    // Base case: If all vertices are assigned a color, return true
    if (v == V)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++)
    {
        // Check if the assignment of color c to vertex v is possible
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            // Proceed to the next vertex
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If assignment of color c to vertex v does not lead to a
            // solution, remove it and try a different color
            color[v] = 0;
        }
    }

    // If no colors can be assigned to this vertex, return false
    return false;
}

// Main function to solve graph coloring problem
bool graphColoring(bool graph[V][V], int m)
{
    // Initialize all color values as 0
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call recursive function to solve graph coloring problem
    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist");
        return false;
    }

    // Print the solution
    printSolution(color);
    return true;
}

// Driver program to test above functions
int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // Number of colors

    printf("Graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    graphColoring(graph, m);

    return 0;
}
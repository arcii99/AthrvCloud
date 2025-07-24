//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices

// Function to check if current color assignment is safe for vertex
bool isSafe(int vertex, int graph[V][V], int color[V], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[vertex][i] && c == color[i])
            return false;
    return true;
}

// Recursive function to solve graph coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[V], int vertex)
{
    if (vertex == V) // All vertices are assigned with a color
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, graph, color, c))
        {
            color[vertex] = c;
            if (graphColoringUtil(graph, m, color, vertex + 1))
                return true;
            color[vertex] = 0; // Backtracking
        }
    }

    return false;
}

// Function to print the solution
void printSolution(int color[V])
{
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

// Function to solve graph coloring problem with given number of colors
bool graphColoring(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0; // Initialize all vertex colors as 0

    if (graphColoringUtil(graph, m, color, 0)) // Start with vertex 0
    {
        printSolution(color);
        return true;
    }

    printf("Solution does not exist.\n");
    return false;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}}; // Example graph, change it as per requirement

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
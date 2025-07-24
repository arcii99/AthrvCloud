//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of vertices and colors
#define V 5
#define COLORS 4

// Print the solution matrix
void printSolution(int color[])
{
    printf("The assigned colors are:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
    printf("\n");
}

// Checks if the color assignment is valid
bool isSafe(int graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] && color[j] == color[i])
                return false;
        }
    }
    return true;
}

// Color vertices recursively
bool graphColoringUtil(int graph[V][V], int m, int color[V], int v)
{
    if (v == V)
    {
        if (isSafe(graph, color))
        {
            printSolution(color);
            return true;
        }
        return false;
    }

    for (int c = 1; c <= m; c++)
    {
        color[v] = c;
        if (graphColoringUtil(graph, m, color, v + 1))
            return true;
        color[v] = 0;
    }
    return false;
}

// Graph coloring function
bool graphColoring(int graph[V][V], int m)
{
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist.\n");
        return false;
    }

    return true;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 1, 0},
                       {1, 0, 1, 0, 1},
                       {1, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1},
                       {0, 1, 0, 1, 0}};

    printf("The graph:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Color the graph with 4 colors
    int m = COLORS;
    if (graphColoring(graph, m) == false)
        printf("Solution does not exist.\n");
    else
        printf("Solution exists.\n");

    return 0;
}
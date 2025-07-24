//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

int graph[V][V] = {
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0}
}; // Graph represented by adjacency matrix

void printSolution(int color[])
{
    printf("Coloring solution:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

bool isSafe(int v, int c, int color[])
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int color[], int m, int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c, color))
        {
            color[v] = c;

            if (graphColoringUtil(color, m, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = 0;
    }

    if (!graphColoringUtil(color, m, 0))
    {
        printf("Solution does not exist!");
        return false;
    }

    printSolution(color);
    return true;
}

int main()
{
    int m = 3; // Number of colors

    if (!graphColoring(m))
        printf("No solution exists");
    return 0;
}
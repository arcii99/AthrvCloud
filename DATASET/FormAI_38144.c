//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>

int graph[5][5] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 1, 1},
                   {1, 1, 0, 1, 1},
                   {1, 1, 1, 0, 1},
                   {0, 1, 1, 1, 0}};

int n = 5;

int color[5];

void printColors() // Print the colors of vertices
{
    printf("Colors of vertices: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int isSafe(int vertex, int c) //Check if color c is safe for vertex
{
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] && c == color[i])
        {
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(int vertex) // Recursive utility function to assign colors
{
    if (vertex == n)
    {
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (isSafe(vertex, i))
        {
            color[vertex] = i;

            if (graphColoringUtil(vertex + 1))
            {
                return 1;
            }

            color[vertex] = 0;
        }
    }

    return 0;
}

void graphColoring() // Main function to assign colors
{
    if (graphColoringUtil(0))
    {
        printColors();
    }
    else
    {
        printf("No solution exists.");
    }
}

int main()
{
    graphColoring();
    return 0;
}
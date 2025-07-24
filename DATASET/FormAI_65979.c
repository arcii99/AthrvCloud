//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define V 4

/* Function to check if assigning a color to given vertex is safe */
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

/* Recursive function to solve the graph coloring problem */
int graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

/* Function to solve graph coloring problem using backtracking */
int graphColoring(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }

    // Solution exists
    printf("Solution Exists: The following are the assigned colors for each vertex:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i + 1, color[i]);
    return 1;
}

/* Main function */
int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
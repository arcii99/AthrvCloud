//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>
#define V 4

void printSolution(int color[])
{
    printf("The assigned colors are:\n");
    for (int i = 0; i < V; i++)
      printf("%d ", color[i]);
    printf("\n");
}

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v+1) == true)
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        printf("Solution does not exist\n");
        return false;
    }
    printSolution(color);
    return true;
}

int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // number of colors
    graphColoring(graph, m);
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 4

void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m,int color[V], int v)
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
    for (int i = 1; i <= m; i++)
    {
        color[v] = i;
        if (graphColoringUtil(graph, m, color, v + 1))
            return true;
        color[v] = 0;
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist");
        return false;
    }
    return true;
}

void printSolution(int color[])
{
    printf("Solution Exists:"
            "Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}

int main()
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
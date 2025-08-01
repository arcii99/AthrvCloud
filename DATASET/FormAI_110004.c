//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define V 5

bool isSafe(int v, bool graph[V][V],
    int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (
            graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColorUtil(bool graph[V][V],
    int m, int color[V], int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColorUtil(
                    graph, m, color, v + 1)
                == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(
    bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColorUtil(
            graph, m, color, 0)
        == false) {
        printf("\nSolution does not exist");
        return false;
    }

    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    return true;
}

int main(){
    bool graph[V][V] = {
        { 0, 1, 1, 1, 0 },
        { 1, 0, 1, 0, 1 },
        { 1, 1, 0, 1, 0 },
        { 1, 0, 1, 0, 1 },
        { 0, 1, 0, 1, 0 }
    };

    int m = 3;

    graphColoring(graph, m);
    return 0;

}
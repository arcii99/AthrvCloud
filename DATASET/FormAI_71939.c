//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

// Number of vertices
#define N 5

// Function to find whether a vertex can be assigned
// particular color or not
bool isSafe(int graph[N][N], int color[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (graph[i][j] && color[j] == color[i])
                return false;
        }
    }
    return true;
}

// Function to solve graph coloring problem
bool graphColorUtil(int graph[N][N], int m, int color[], int v)
{
    if (v == N)
        return true;

    for (int c = 1; c <= m; c++)
    {
        color[v] = c;

        if (isSafe(graph, color))
        {
            if (graphColorUtil(graph, m, color, v + 1))
                return true;
        }

        color[v] = 0;
    }

    return false;
}

// Function to print solution
void printSolution(int color[])
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < N; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

// Function to solve graph coloring problem using backtracking
bool graphColoring(int graph[N][N], int m)
{
    int color[N];

    for (int i = 0; i < N; i++)
        color[i] = 0;

    if (!graphColorUtil(graph, m, color, 0))
        return false;

    printSolution(color);
    return true;
}

int main()
{
    int graph[N][N] = {{0, 1, 1, 1, 0},
                       {1, 0, 1, 0, 1},
                       {1, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1},
                       {0, 1, 0, 1, 0}};

    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
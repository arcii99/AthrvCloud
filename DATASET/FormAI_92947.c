//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define N 5      // Number of vertices
#define M 2      // Number of colors

int graph[N][N] = {{0, 1, 0, 1, 1},
                   {1, 0, 1, 0, 0},
                   {0, 1, 0, 1, 0},
                   {1, 0, 1, 0, 1},
                   {1, 0, 0, 1, 0}}; // Adjacency matrix representation

// Function to check if it is safe to color a vertex with a given color
int isSafe(int c, int vertex, int color[])
{
    for (int i = 0; i < N; i++)
        if (graph[vertex][i] && c == color[i])
            return 0;
    return 1;
}

// Function to assign colors to all vertices
void assignColors(int vertex, int color[])
{
    // If all vertices are colored, print the solution
    if (vertex == N)
    {
        printf("Solution Exists: ");
        for (int i = 0; i < N; i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }

    // Try different colors for the vertex
    for (int c = 1; c <= M; c++)
    {
        // Check if it's safe to color the vertex with current color
        if (isSafe(c, vertex, color))
        {
            color[vertex] = c;
            assignColors(vertex + 1, color);
            color[vertex] = 0;
        }
    }
}

int main()
{
    int color[N] = {0}; // Initialize all colors as 0
    assignColors(0, color);
    return 0;
}
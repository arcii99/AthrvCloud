//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5 // number of vertices
#define M 2 // number of colors (e.g. {0, 1})

int adj[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int colors[N]; // array to store the colors of each vertex

// function to check if adjacent vertices have the same color
bool isSafe(int vertex, int color)
{
    for (int i = 0; i < N; i++) {
        if (adj[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

// recursive function to solve the graph coloring problem
bool graphColoring(int vertex)
{
    // base case: all vertices are colored
    if (vertex == N) {
        return true;
    }

    // try all possible colors for the current vertex
    for (int i = 0; i < M; i++) {
        if (isSafe(vertex, i)) {
            // assign the color to the current vertex
            colors[vertex] = i;

            // recursively color the next vertices
            if (graphColoring(vertex + 1)) {
                return true;
            }

            // backtrack and try a different color
            colors[vertex] = -1;
        }
    }

    return false;
}

int main()
{
    // initialize the colors of all vertices to -1
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }

    if (graphColoring(0)) {
        // print the colors of all vertices
        for (int i = 0; i < N; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph cannot be colored using %d colors.\n", M);
    }

    return 0;
}
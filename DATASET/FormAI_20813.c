//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// define maximum number of vertices in the graph
#define N 5

// define colors
#define WHITE 0
#define GRAY 1
#define BLACK 2

// function to check if colored properly
int isSafe(int vertex, int graph[N][N], int color[N], int col) {
    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] == 1 && color[i] == col)
            return 0; // color already there, not safe
    }
    return 1; // safe to color
}

// function to color the graph
void colorGraph(int vertex, int graph[N][N], int m, int color[N]) {
    if (vertex == N) {
        // all vertices have been assigned a color
        printf("Colors used for each vertex are: ");
        for (int i = 0; i < N; i++)
            printf("%d ", color[i]);
        printf("\n");
        return;
    }

    // iterate through all colors
    for (int i = 1; i <= m; i++) {
        if (isSafe(vertex, graph, color, i)) {
            // assign color and continue with next vertex
            color[vertex] = i;
            colorGraph(vertex + 1, graph, m, color);
            color[vertex] = WHITE; // backtrack
        }
    }
}

int main() {
    // create graph to color
    int graph[N][N] = {{0, 1, 0, 1, 1},
                       {1, 0, 1, 0, 1},
                       {0, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1},
                       {1, 1, 0, 1, 0}};

    // initialize array to store color for each vertex
    int color[N];
    for (int i = 0; i < N; i++)
        color[i] = WHITE;

    // color the graph with 3 colors
    int m = 3;
    colorGraph(0, graph, m, color);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5   // Number of vertices in the graph

bool isSafe(int v, int graph[N][N], int color[], int c) {
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[N][N], int m, int color[], int v) {
    if (v == N) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v+1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

void graphColoring(int graph[N][N], int m) {
    int color[N];

    for (int i = 0; i < N; i++) {
        color[i] = 0;
    }

    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution exists with %d colors.\n", m);
        printf("The colors of vertices are: ");

        for (int i = 0; i < N; i++) {
            printf("%d ", color[i]);
        }

        printf("\n");
    } else {
        printf("No solution exists with %d colors.\n", m);
    }
}

int main() {
    int graph[N][N] = {
        { 0, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 1 },
        { 1, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 1 },
        { 1, 1, 0, 1, 0 }
    };

    graphColoring(graph, 3);

    return 0;
}
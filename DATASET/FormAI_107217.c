//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define N 5

int graph[N][N] = {
    {0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0}
};

int color[N];

int is_valid_coloring(int v, int c)
{
    int i;
    for (i = 0; i < N; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graph_coloring(int v)
{
    int c;
    if (v == N)
        return 1;
    for (c = 1; c <= N; c++) {
        if (is_valid_coloring(v, c)) {
            color[v] = c;
            if (graph_coloring(v + 1))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main()
{
    int i, j;
    if (graph_coloring(0)) {
        printf("The vertices are colored as:\n");
        for (i = 0; i < N; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph is not colorable\n");
    }
    return 0;
}
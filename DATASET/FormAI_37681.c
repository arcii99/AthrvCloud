//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int n; // number of vertices
int m; // number of edges
int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int colors[MAX_VERTICES]; // color of each vertex

int get_color(int vertex)
{
    bool used[MAX_COLORS] = {false};
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] && colors[i]) {
            used[colors[i] - 1] = true;
        }
    }
    for (int i = 0; i < MAX_COLORS; i++) {
        if (!used[i]) {
            return i + 1;
        }
    }
}

void color_graph()
{
    for (int i = 0; i < n; i++) {
        colors[i] = get_color(i);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    color_graph();
    for (int i = 0; i < n; i++) {
        printf("Vertex %d has color %d\n", i, colors[i]);
    }
    return 0;
}
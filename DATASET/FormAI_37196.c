//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_DEGREE 100

typedef struct {
    int n; // number of vertices
    int m; // number of edges
    int edges[MAX_VERTICES][MAX_DEGREE]; // adjacency info
    int degree[MAX_VERTICES]; // outdegree of each vertex
} Graph;

void init_graph(Graph *g, int n) {
    int i;
    g -> n = n;
    g -> m = 0;
    for (i = 0; i < n; i++)
        g -> degree[i] = 0;
}

void insert_edge(Graph *g, int x, int y) {
    g -> edges[x][g -> degree[x]] = y;
    g -> degree[x]++;
    g -> edges[y][g -> degree[y]] = x;
    g -> degree[y]++;
    g -> m++;
}

int count_colors(int *colors, int n) {
    int i, max = 0;
    for (i = 0; i < n; i++) {
        if (colors[i] > max)
            max = colors[i];
    }
    return max + 1;
}

bool is_safe(Graph *g, int v, int color[], int c) {
    int i;
    for (i = 0; i < g -> degree[v]; i++) {
        int u = g -> edges[v][i];
        if (color[u] == c)
            return false;
    }
    return true;
}

void graph_coloring(Graph *g) {
    int i, j;
    int colors[MAX_VERTICES];
    for (i = 0; i < g -> n; i++)
        colors[i] = -1;
    colors[0] = 0;
    for (i = 1; i < g -> n; i++) {
        for (j = 0; j < g -> degree[i]; j++) {
            int u = g -> edges[i][j];
            if (colors[u] != -1)
                colors[i] = colors[u];
        }
        if (colors[i] == -1) {
            int c;
            for (c = 0; c < g -> n; c++) {
                if (is_safe(g, i, colors, c)) {
                    colors[i] = c;
                    break;
                }
            }
        }
    }
    printf("Number of colors = %d\n", count_colors(colors, g -> n));
    for (i = 0; i < g -> n; i++)
        printf("Vertex %d --> Color %d\n", i, colors[i]);
}

int main() {
    Graph g;
    int n = 10;
    init_graph(&g, n);
    insert_edge(&g, 0, 1);
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 2);
    insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 5);
    insert_edge(&g, 3, 4);
    insert_edge(&g, 3, 5);
    insert_edge(&g, 4, 5);
    insert_edge(&g, 6, 7);
    insert_edge(&g, 6, 8);
    insert_edge(&g, 6, 9);
    insert_edge(&g, 7, 8);
    insert_edge(&g, 7, 9);
    insert_edge(&g, 8, 9);
    graph_coloring(&g);
    return 0;
}
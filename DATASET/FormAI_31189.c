//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define N 5

int colors[N];
bool is_safe(int G[][N], int v, int c) {
    for (int i = 0; i < N; i++) {
        if (G[v][i] && c == colors[i])
            return false;
    }
    return true;
}
bool graph_coloring_util(int G[][N], int m, int v) {
    if (v == N) return true;
    for (int c = 1; c <= m; c++) {
        if (is_safe(G, v, c)) {
            colors[v] = c;
            if (graph_coloring_util(G, m, v + 1))
                return true;
            colors[v] = 0;
        }
    }
    return false;
}
bool graph_coloring(int G[][N], int m) {
    for (int i = 0; i < N; i++)
        colors[i] = 0;
    if (!graph_coloring_util(G, m, 0)) {
        return false;
    }
    printf("Color assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
    return true;
}
int main() {
    int G[N][N] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    // graph is represented as an adjacency matrix
    int m = 3; // number of colors
    if (!graph_coloring(G, m)) {
        printf("No solutions possible\n");
    }
    return 0;
}
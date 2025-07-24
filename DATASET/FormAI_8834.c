//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define V 7
#define COLORS 3

int graph[V][V] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 0}
};

int colors[V] = {-1};

int is_safe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == colors[i]) {
            return 0;
        }
    }
    return 1;
}

void print_colors() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }
    printf("\n");
}

void graph_coloring(int v) {
    if (v == V) {
        print_colors();
        return;
    }

    #pragma omp parallel for shared(colors, graph) schedule(static, 1)
    for (int c = 0; c < COLORS; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;
            graph_coloring(v+1);
            colors[v] = -1;
        }
    }
}

int main() {
    graph_coloring(0);
    return 0;
}
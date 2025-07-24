//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000
#define MAX_DEGREE 100

typedef struct {
    int edges[MAXV+1][MAX_DEGREE];
    int degree[MAXV+1];
    int nedges;
    int nvertices;
} graph;

int color[MAXV+1];

void read_graph(graph *g) {
    int i, j, x, y;
    printf("Enter number of vertices: ");
    scanf("%d", &(g->nvertices));
    printf("Enter number of edges: ");
    scanf("%d", &(g->nedges));
    for (i = 1; i <= g->nvertices; i++)
        g->degree[i] = 0;
    for (i = 1; i <= g->nedges; i++) {
        printf("Enter edge %d: ", i);
        scanf("%d %d", &x, &y);
        g->edges[x][g->degree[x]] = y;
        g->edges[y][g->degree[y]] = x;
        g->degree[x]++;
        g->degree[y]++;
    }
}

int welsh_powell(graph *g) {
    int i, j, k, max_degree = 0, color_count = 0;
    int available_color[MAXV+1] = {0};

    for (i = 1; i <= g->nvertices; i++)
        color[i] = 0;

    for (i = 1; i <= g->nvertices; i++) {
        if (g->degree[i] > max_degree)
            max_degree = g->degree[i];
    }

    for (k = 1; k <= g->nvertices; k++) {
        int v = 0;
        for (i = 1; i <= g->nvertices; i++) {
            if (!color[i]) {
                if (v == 0 || g->degree[i] > g->degree[v])
                    v = i;
            }
        }
        if (v == 0)
            break;

        for (i = 1; i <= g->nvertices; i++)
            available_color[i] = 1;

        for (i = 0; i < g->degree[v]; i++) {
            int neighbor = g->edges[v][i];
            if (color[neighbor] != 0)
                available_color[color[neighbor]] = 0;
        }

        for (i = 1; i <= g->nvertices; i++) {
            if (available_color[i]) {
                color[v] = i;
                color_count++;
                break;
            }
        }
    }
    return color_count;
}

void print_coloring(graph *g) {
    int i, j;
    printf("Vertex colors:\n");
    for (i = 1; i <= g->nvertices; i++)
        printf("Vertex %d: color %d\n", i, color[i]);
}

int main() {
    graph g;
    read_graph(&g);
    int color_count = welsh_powell(&g);
    printf("\nTotal number of colors used: %d\n", color_count);
    print_coloring(&g);
    return 0;
}
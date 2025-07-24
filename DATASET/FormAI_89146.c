//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
/*
 * Graph Coloring Problem
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define V 5

bool is_safe(int graph[V][V], int color[V], int v, int c)
{
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int graph[V][V], int m, int color[V], int v)
{
    if (v == V) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (is_safe(graph, color, v, c)) {
            color[v] = c;
            if (graph_coloring_util(graph, m, color, v + 1)) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

void graph_coloring(int graph[V][V], int m)
{
    int color[V] = {0};
    if (!graph_coloring_util(graph, m, color, 0)) {
        printf("Failed to color the graph\n");
    } else {
        printf("The graph is colored with at most %d colors as follows:\n", m);
        for (int i = 0; i < V; i++) {
            printf("Vertex %d is colored with color %d\n", i + 1, color[i]);
        }
    }
}

int main()
{
    int graph[V][V] = {
        { 0, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 0 },
        { 1, 1, 0, 1, 1 },
        { 0, 1, 1, 0, 1 },
        { 1, 0, 1, 1, 0 }
    };
    int max_colors = 3; /* Change this to experiment with different cases */
    printf("Graph Coloring Problem\n");
    printf("======================\n");
    printf("Graph:\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("Maximum number of colors: %d\n", max_colors);
    printf("Solving the graph coloring problem...\n");
    sleep(2);
    graph_coloring(graph, max_colors);
    printf("Done!\n");
    return 0;
}
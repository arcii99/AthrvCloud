//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#define MAX_COLOR 10

int graph[10][10] = {
    {0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 1, 1, 1, 0, 0},
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
};

int n;
int color_map[10];

int is_safe(int node, int color)
{
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && color_map[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graph_color(int node)
{
    if (node == n) {
        return 1;
    }

    for (int color = 1; color <= MAX_COLOR; color++) {
        if (is_safe(node, color)) {
            color_map[node] = color;

            if (graph_color(node + 1)) {
                return 1;
            }

            color_map[node] = 0;
        }
    }

    return 0;
}

int main()
{
    n = 10;
    if (graph_color(0)) {
        printf("Coloring Possible:\n");
        for(int i=0; i<n; i++) {
            printf("Node %d : Color %d\n", i, color_map[i]);
        }
    } else {
        printf("Coloring NOT Possible.\n");
    }

    return 0;
}
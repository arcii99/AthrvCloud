//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 6
#define MAX_COLORS 3

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

int colors[MAX_VERTICES];

bool is_valid(int vertex, int color) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

bool color_graph(int vertex) {
    if (vertex == MAX_VERTICES) {
        return true;
    }
    for (int color = 1; color <= MAX_COLORS; color++) {
        if (is_valid(vertex, color)) {
            colors[vertex] = color;
            if (color_graph(vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    if (color_graph(0)) {
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("No valid coloring found.\n");
    }
    return 0;
}
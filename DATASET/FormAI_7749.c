//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define MAX_COLORS 3

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 1, 1, 0}
};

int colors[MAX_VERTICES] = {0};

void printColors() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d colored with %d\n", i+1, colors[i]);
    }
}

int isSafe(int v, int c) {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (graph[v][i] && c == colors[i]) return 0;
    }
    return 1;
}

int color(int v) {
    int c;
    for (c = 1; c <= MAX_COLORS; c++) {
        if (isSafe(v, c)) {
            return c;
        }
    }
    return 0;
}

void colorGraph() {
    int i, c;
    colors[0] = 1;
    for (i = 1; i < MAX_VERTICES; i++) {
        colors[i] = color(i);
    }
}

int main() {
    colorGraph();
    printColors();
    return 0;
}
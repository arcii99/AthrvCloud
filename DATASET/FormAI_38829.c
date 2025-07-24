//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdbool.h>

#define MAX_COLOR 4
#define MAX_VERTICES 5

int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
};

int colors[MAX_VERTICES] = {0};
bool isValid(int vertex, int color) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}
bool graphColoring(int vertex) {
    if (vertex == MAX_VERTICES) {
        return true;
    }

    for (int i = 1; i <= MAX_COLOR; i++) {
        if (isValid(vertex, i)) {
            colors[vertex] = i;
            if (graphColoring(vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

int main() {
    if (graphColoring(0)) {
        printf("The minimum number of colors required is %d\n", MAX_COLOR);
        printf("The colors assigned to the vertices are: \n");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Graph coloring is not possible\n");
    }
    return 0;
}
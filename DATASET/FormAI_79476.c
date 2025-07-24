//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Touring
#include <stdio.h>

#define VERTEX_NUM 4

int graph[VERTEX_NUM][VERTEX_NUM] = { // graph adjacency matrix
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int colors[VERTEX_NUM] = {}; // used to store the color of each vertex

int is_valid_color(int vertex_index, int color_index) {
    for (int i = 0; i < VERTEX_NUM; i++) {
        if (graph[vertex_index][i] == 1 && colors[i] == color_index) {
            return 0; // color not valid
        }
    }
    return 1; // color valid
}

int graph_coloring(int vertex_index) {
    if (vertex_index == VERTEX_NUM) {
        return 1; // all vertices successfully colored
    }
    for (int color_index = 1; color_index <= VERTEX_NUM; color_index++) {
        if (is_valid_color(vertex_index, color_index)) {
            colors[vertex_index] = color_index;
            if (graph_coloring(vertex_index + 1) == 1) {
                return 1;
            }
            colors[vertex_index] = 0; // reset color
        } 
    }
    return 0; // no valid coloring found
}

int main() {
    if (graph_coloring(0) == 1) {
        printf("Graph is %d-colorable with colors: ", VERTEX_NUM);
        for (int i = 0; i < VERTEX_NUM; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        printf("Graph is not %d-colorable\n", VERTEX_NUM);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define MAX_COLOR 3

int graph[MAX_VERTEX][MAX_VERTEX];
int vertex_color[MAX_VERTEX] = {0};

int can_color(int v, int c) {
    for (int i = 0; i < MAX_VERTEX; i++) {
        if (graph[v][i] && vertex_color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int v) {
    if (v == MAX_VERTEX) {
        return 1;
    }
    for (int c = 1; c <= MAX_COLOR; c++) {
        if (can_color(v, c)) {
            vertex_color[v] = c;
            if (graph_coloring(v + 1)) {
                return 1;
            }
            vertex_color[v] = 0;
        }
    }
    return 0;
}

int main() {
    //initialize the graph
    graph[0][1] = graph[1][0] = 1;
    graph[0][4] = graph[4][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[4][5] = graph[5][4] = 1;
    graph[5][6] = graph[6][5] = 1;
    graph[6][7] = graph[7][6] = 1;
    graph[7][8] = graph[8][7] = 1;
    graph[8][9] = graph[9][8] = 1;

    if (graph_coloring(0)) {
        printf("Graph can be colored using %d colors.\n", MAX_COLOR);
        printf("Vertex colors:\n");
        for (int i = 0; i < MAX_VERTEX; i++) {
            printf("%d ", vertex_color[i]);
        }
        printf("\n");
    } else {
        printf("Graph cannot be colored using %d colors.\n", MAX_COLOR);
    }

    return 0;
}
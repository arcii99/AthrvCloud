//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 //total vertices to consider

bool isSafe(int vertex, int graph[V][V], int vertexColor[], int color) {
    int i;
    for(i = 0; i < V; i++) {
        if(graph[vertex][i] && color == vertexColor[i]) {
            return false;
        }
    }

    return true;
}

bool colorGraph(int graph[V][V], int vertexColor[], int vertex) {
    if(vertex == V) {
        return true;
    }

    int color;
    for(color = 1; color <= V; color++) {
        if(isSafe(vertex, graph, vertexColor, color)) {
            vertexColor[vertex] = color;

            if(colorGraph(graph, vertexColor, vertex+1) == true) {
                return true;
            }

            vertexColor[vertex] = 0;
        }
    }

    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int vertexColor[V];

    int i;
    for(i = 0; i < V; i++) {
        vertexColor[i] = 0;
    }

    if(colorGraph(graph, vertexColor, 0) == true) {
        printf("Graph can be colored using at most %d colors.\n", V);
        printf("The colors of vertices are: \n");
        for(i = 0; i < V; i++) {
            printf("Vertex %d - Color %d\n", i+1, vertexColor[i]);
        }
    }
    else {
        printf("Graph cannot be colored using at most %d colors.\n", V);
    }

    return 0;
}
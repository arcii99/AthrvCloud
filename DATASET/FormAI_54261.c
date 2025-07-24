//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define V 8 // number of vertices

bool isSafe(int graph[V][V], int colors[V], int vertex, int color) {

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }

    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int colors[V], int vertex) {

    if (vertex == V) {
        return true;
    }

    for (int i = 1; i <= m; i++) {

        if (isSafe(graph, colors, vertex, i)) {
            colors[vertex] = i;
            if (graphColoringUtil(graph, m, colors, vertex + 1)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }

    return false;
}

bool graphColoring(int graph[V][V], int m) {

    int colors[V];
    for (int i = 0; i < V; i++) {
        colors[i] = 0; // no colors assigned initially
    }

    if (graphColoringUtil(graph, m, colors, 0) == false) {
        printf("Failed to color the graph.\n");
        return false;
    }

    printf("Vertices colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: color %d\n", i+1, colors[i]);
    }

    return true;
}

int main() {

    int graph[V][V] = {
            // surrealistic graph
            {0, 1, 1, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 1, 1},
            {0, 0, 0, 1, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 1, 1, 0}
    };

    srand(time(NULL)); // surrealistic random seed

    int m = 5 + rand() % 10; // surrealistic number of colors between 5 and 14
    printf("Surrealistic Graph Coloring Problem:\n");
    printf("Using %d colors...\n", m);

    if (graphColoring(graph, m)) {
        printf("Successfully colored the surrealistic graph!\n");
    }

    return 0;
}
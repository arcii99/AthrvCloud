//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>
#define V 4

// A function to check if a color can be used on vertex
int isSafe(int vertex, int graph[V][V], int colors[V], int color) {
    int i;
    for (i = 0; i < V; i++)
        if (graph[vertex][i] && color == colors[i])
            return 0;   // not safe
    return 1;           // safe
}

// A recursive function to color vertices
int graphColoring(int graph[V][V], int colors[V], int vertex) {
    int i;
    if (vertex == V)
        return 1;       // all vertices are colored

    for (i = 1; i <= V; i++) {  //try different colors
        if (isSafe(vertex, graph, colors, i)) {
            colors[vertex] = i;
            if (graphColoring(graph, colors, vertex + 1))
                return 1;
            colors[vertex] = 0;
        }
    }
    return 0;           // cannot color this vertex
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};
    int colors[V] = {0};

    if (graphColoring(graph, colors, 0))
        for (int i = 0; i < V; i++)
            printf("Vertex %d has color %d\n", i, colors[i]);
    else
        printf("No solution exists\n");

    return 0;
}
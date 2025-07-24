//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int colors[MAX_VERTICES]; // array to store the color assigned to each vertex
int num_vertices; // number of vertices in the graph

// function to check if a color can be assigned to a vertex
bool is_color_valid(int vertex, int color) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false; // neighbor has the same color
        }
    }
    return true;
}

// function to assign colors to vertices recursively
bool assign_colors(int vertex) {
    if (vertex == num_vertices) {
        return true; // all vertices have been assigned a color
    }
    for (int color = 1; color <= num_vertices; color++) {
        if (is_color_valid(vertex, color)) {
            colors[vertex] = color;
            if (assign_colors(vertex + 1)) {
                return true; // found a valid coloring
            }
            colors[vertex] = 0; // backtrack
        }
    }
    return false; // cannot assign a valid color to this vertex
}

int main() {
    // read input
    scanf("%d", &num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // assign colors to vertices
    if (assign_colors(0)) {
        // print the coloring
        for (int i = 0; i < num_vertices; i++) {
            printf("%d\n", colors[i]);
        }
    } else {
        printf("No valid coloring found\n");
    }

    return 0;
}
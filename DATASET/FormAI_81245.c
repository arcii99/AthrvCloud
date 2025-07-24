//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* This program solves the Graph Coloring Problem */
/* In this problem, we color the vertices of a graph so that no two adjacent vertices have the same color */

/* Set the maximum number of vertices and colors */
#define MAX_VERTICES 10
#define MAX_COLORS 4

/* Define the graph matrix and color array */
int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

/* Function to check if a vertex can be colored with the given color */
int is_color_valid(int vertex, int color) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && color == colors[i]) {
            return 0;
        }
    }
    return 1;
}

/* Function to recursively color the vertices of the graph */
int color_vertices(int vertex) {
    /* If all vertices have been colored, return 1 */
    if (vertex == MAX_VERTICES) {
        return 1;
    }

    /* Try all possible colors for this vertex */
    for (int i = 1; i <= MAX_COLORS; i++) {
        /* Check if this color is valid for this vertex */
        if (is_color_valid(vertex, i)) {
            colors[vertex] = i;
            /* Recursively color the next vertex */
            if (color_vertices(vertex + 1)) {
                return 1;
            }
            colors[vertex] = 0;
        }
    }

    /* If no color can be chosen for this vertex, return 0 */
    return 0;
}

/* Main function */
int main() {
    /* Initialize the graph matrix */
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;

    /* Color the vertices of the graph recursively */
    if (color_vertices(0)) {
        /* Print the colors of the vertices */
        printf("Vertex colors:\n");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("Failed to color vertices.\n");
    }

    return 0;
}
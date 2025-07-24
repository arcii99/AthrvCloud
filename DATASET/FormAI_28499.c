//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices
#define MAX_VERTICES 5

// Define the number of colors
#define NUM_COLORS 3

// Define the adjacency matrix
int adj_matrix[MAX_VERTICES][MAX_VERTICES] = {
    {0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0},
};

// Define the color array
int color[MAX_VERTICES];

// Define the function prototypes
int is_safe(int v, int c);
void graph_color(int v);

// Main function
int main() {
    // Color each vertex with -1 initially
    for (int i = 0; i < MAX_VERTICES; i++) {
        color[i] = -1;
    }
    // Call the graph color function for the first vertex
    graph_color(0);
    // Print the result
    printf("Coloring result for the graph:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    return 0;
}

// Check if it is safe to color a vertex with a certain color
int is_safe(int v, int c) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (adj_matrix[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to color the graph
void graph_color(int v) {
    // Base case: if all vertices are colored
    if (v == MAX_VERTICES) {
        return;
    }
    // Try to color the vertex with each color
    for (int c = 0; c < NUM_COLORS; c++) {
        if (is_safe(v, c)) {
            color[v] = c;
            graph_color(v+1);
            color[v] = -1;
        }
    }
}
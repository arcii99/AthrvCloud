//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the number of vertices in the graph
#define N 7

// Define the maximum number of colors
#define MAX_COLORS 4

// Define a 2D matrix to represent the adjacency matrix of the graph
int adj_matrix[N][N] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1},
    {0, 1, 1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 1, 0}
};

// Define an array to store the color of each vertex
int vertex_color[N];

// Declare the graph coloring function
bool graph_coloring(int vertex, int color);

int main() {
    // Set the random seed
    srand(time(NULL));

    // Print the adjacency matrix
    printf("The adjacency matrix of the graph:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    // Color the graph
    if (graph_coloring(0, 0)) {
        // If the graph was successfully colored, print the result
        printf("The graph can be colored with %d colors:\n", MAX_COLORS);
        for (int i = 0; i < N; i++) {
            printf("Vertex %d color: %d\n", i, vertex_color[i]);
        }
    } else {
        // If the graph cannot be colored with the given number of colors, print an error message
        printf("The graph cannot be colored with %d colors!\n", MAX_COLORS);
    }

    return 0;
}

bool graph_coloring(int vertex, int color) {
    // Check if all vertices have been colored
    if (vertex == N) {
        return true;
    }

    // Try to color the current vertex with the given color
    if (vertex == 0 || adj_matrix[vertex-1][vertex] == 0) {
        vertex_color[vertex] = color;
        // Try to color the next vertex with a different color
        for (int c = 0; c < MAX_COLORS; c++) {
            // Generate a random next color
            int next_color = rand() % MAX_COLORS;
            if (next_color == color) {
                next_color = (color + 1) % MAX_COLORS;
            }
            // Color the next vertex with the randomly generated color
            if (graph_coloring(vertex+1, next_color)) {
                return true;
            }
        }
        // If all colors have been tried and none worked, backtrack
        vertex_color[vertex] = -1;
        return false;
    } else {
        // If the current vertex is adjacent to the previous vertex, skip it
        return graph_coloring(vertex+1, color);
    }
}
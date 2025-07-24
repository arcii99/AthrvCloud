//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Adjacency matrix for storing the graph
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};

// Array to keep track of the color of each vertex
int color[MAX_VERTICES];

// Number of vertices in the graph
int num_vertices;

// Function to check if a vertex can be assigned a particular color
bool is_valid_color(int vertex, int c) {
    for (int i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[vertex][i] && color[i] == c) {
            return false; // Vertex has same color as an adjacent vertex
        }
    }
    return true;
}

// Function to solve the graph coloring problem
bool graph_coloring(int vertex) {
    if (vertex == num_vertices) { // All vertices have been colored
        return true;
    }
    for (int c = 1; c <= num_vertices; c++) {
        if (is_valid_color(vertex, c)) {
            color[vertex] = c; // Vertex is colored with color c
            if (graph_coloring(vertex+1)) {
                return true; // Solution found
            }
            color[vertex] = 0; // backtrack
        }
    }
    return false; // Solution not found
}

int main() {
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);

    printf("Enter the adjacency matrix of the graph (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    if (graph_coloring(0)) {
        printf("The vertices can be colored with the following colors:\n");
        for (int i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("Sorry, it is not possible to color the vertices of the graph.\n");
    }

    return 0;
}
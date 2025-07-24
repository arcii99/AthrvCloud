//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define max number of vertices and colors
#define N 5
#define COLORS 3

// Define adjacency matrix
int adj_matrix[N][N] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

// Define array of assigned colors
int assigned_colors[N];

// Define function to check if a color is valid for a vertex
bool is_color_valid(int vertex, int color) {
    // Check if any adjacent vertices have the same color
    for(int i=0; i<N; i++) {
        if(adj_matrix[vertex][i] && color == assigned_colors[i]) {
            return false;
        }
    }
    // If no adjacent vertices have the same color, color is valid
    return true;
}

// Define function to recursively color vertices
bool color_vertices(int vertex) {
    // Base case: all vertices have been assigned a color
    if(vertex == N) {
        return true;
    }
    // Try each color for the current vertex
    for(int color=1; color<=COLORS; color++) {
        // Check if the color is valid
        if(is_color_valid(vertex, color)) {
            assigned_colors[vertex] = color;
            // Recursively color the next vertex
            if(color_vertices(vertex+1)) {
                return true;
            }
            // If the color didn't work, try the next one
            assigned_colors[vertex] = 0;
        }
    }
    // If no colors work, backtrack
    return false;
}

// Define main function
int main() {
    // Initialize array of assigned colors
    for(int i=0; i<N; i++) {
        assigned_colors[i] = 0;
    }
    // Color the vertices recursively
    if(color_vertices(0)) {
        // Print the assigned colors
        printf("Vertex colors:\n");
        for(int i=0; i<N; i++) {
            printf("%d: Color %d\n", i, assigned_colors[i]);
        }
    } else {
        // If no color assignments were possible, print an error message
        printf("Error: No valid color assignments possible!\n");
    }
    return 0;
}
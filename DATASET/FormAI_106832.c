//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define N 6 // Number of vertices

int graph[N][N] = {
    {0, 1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0},
    {1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

int color[N]; // Solution array to store the colors of vertices

/*
A utility function to check if the current color assignment is valid
for the given vertex
*/
int is_valid(int vertex, int color_choice) {
    for (int i = 0; i < N; i++) {
        if (graph[vertex][i] && color_choice == color[i])
            return 0;
    }
    return 1;
}

/*
A recursive utility function to solve the graph coloring problem
*/
int graph_color(int vertex) {
    // If all vertices are colored, return 1
    if (vertex == N)
        return 1;

    // Try all possible colors for this vertex
    for (int i = 1; i <= N; i++) {
        // Check if the color is valid for this vertex
        if (is_valid(vertex, i)) {
            color[vertex] = i;
            // Recur to color the rest of the vertices
            if (graph_color(vertex+1))
                return 1;
            color[vertex] = 0; // Backtrack
        }
    }
    // If none of the colors can be assigned, return 0
    return 0;
}

int main() {
    if (graph_color(0)) {
        printf("The colors assigned to the vertices are:\n");
        for (int i = 0; i < N; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
    } else {
        printf("No solution exists\n");
    }
    return 0;
}
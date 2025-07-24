//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define NUM_VERTICES 5

// function to check if two vertices are adjacent
bool is_adjacent(int graph[NUM_VERTICES][NUM_VERTICES], int vertex1, int vertex2) {
    return graph[vertex1][vertex2] == 1;
}

// function to print the colors assigned to each vertex
void print_colors(int color_assignment[]) {
    printf("Vertex Colors: ");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("%d ", color_assignment[i]);
    }
    printf("\n");
}

// function to check if a given color is valid for the current vertex
bool is_valid_color(int graph[NUM_VERTICES][NUM_VERTICES], int vertex, int color, int color_assignment[]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (is_adjacent(graph, vertex, i) && color_assignment[i] == color) {
            return false;
        }
    }
    return true;
}

// recursive function to assign colors to vertices
bool assign_colors(int graph[NUM_VERTICES][NUM_VERTICES], int num_colors, int vertex, int color_assignment[]) {
    // base case: all vertices are colored
    if (vertex == NUM_VERTICES) {
        return true;
    }
    
    // try coloring the current vertex with each color
    for (int color = 1; color <= num_colors; color++) {
        // check if the current color is valid for the current vertex
        if (is_valid_color(graph, vertex, color, color_assignment)) {
            // assign the color to the current vertex and continue with the next vertex
            color_assignment[vertex] = color;
            if (assign_colors(graph, num_colors, vertex+1, color_assignment)) {
                return true;
            }
            // if we reach here, it means the current color assignment did not lead to a solution
            // we reset the color assignment for the current vertex and try with the next color
            color_assignment[vertex] = 0;
        }
    }
    
    return false;
}

int main() {
    int graph[NUM_VERTICES][NUM_VERTICES] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    
    int num_colors = 3; // we want to color the graph using 3 colors
    int color_assignment[NUM_VERTICES] = {0}; // initialize all colors to 0 (unassigned)
    
    if (assign_colors(graph, num_colors, 0, color_assignment)) {
        printf("Graph can be colored using %d colors.\n", num_colors);
        print_colors(color_assignment);
    } else {
        printf("Graph cannot be colored using %d colors.\n", num_colors);
    }
    
    return 0;
}
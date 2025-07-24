//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// Max colors to color a graph
#define MAX_COLORS 10

// Function to check if the current color assignment is valid for the graph
int is_valid(int graph[][6], int colors[], int vertex, int color) {
    // Iterate through all the vertices adjacent to the given vertex and check if their color matches
    for(int i=0;i<6;i++) {
        if(graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the graph coloring problem using backtracking
int solve_graph_coloring(int graph[][6], int colors[], int vertex, int num_vertices) {
    // Base case: If all vertices have been assigned a color, return 1
    if(vertex == num_vertices) {
        return 1;
    }

    // Try all possible colors for the current vertex
    for(int i=1;i<=MAX_COLORS;i++) {
        // Check if the current color assignment is valid
        if(is_valid(graph, colors, vertex, i)) {
            // Assign the color and move on to the next vertex
            colors[vertex] = i;
            if(solve_graph_coloring(graph, colors, vertex+1, num_vertices)) {
                return 1;
            }
            // Backtrack and try a different color
            colors[vertex] = 0;
        }
    }
    return 0;
}

int main() {
    int graph[6][6] = {
                    {0, 1, 1, 0, 0, 0},
                    {1, 0, 1, 1, 0, 0},
                    {1, 1, 0, 1, 1, 0},
                    {0, 1, 1, 0, 1, 1},
                    {0, 0, 1, 1, 0, 1},
                    {0, 0, 0, 1, 1, 0}
    };

    int colors[6] = {0};

    // Solve the Graph Coloring problem using backtracking
    if(solve_graph_coloring(graph, colors, 0, 6)) {
        printf("Colors assigned to the vertices: ");
        for(int i=0;i<6;i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    }
    else {
        printf("No valid color assignment possible.\n");
    }

    return 0;
}
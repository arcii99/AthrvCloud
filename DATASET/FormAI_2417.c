//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

#define VERTICES 10
#define COLORS 3

int graph[VERTICES][VERTICES]; // The input graph
int colors[VERTICES]; // An array to store the assignments of colors to vertices

// Utility function to check if it is safe to assign the current color to the current vertex
bool isSafe(int vertex, int color) {
    for (int i = 0; i < VERTICES; i++) {
        if (graph[vertex][i] && color == colors[i])
            return false;
    }
    return true;
}

// Function to assign colors to vertices of the graph
void colorGraph() {
    // Initially, mark all vertices as unassigned
    for (int i = 0; i < VERTICES; i++)
        colors[i] = -1;

    // Assign the first color to the first vertex
    colors[0] = 0;

    // Iterate over the remaining vertices and assign colors to them
    for (int i = 1; i < VERTICES; i++) {
        // Iterate over the available colors and find the first one that is safe to assign
        for (int j = 0; j < COLORS; j++) {
            if (isSafe(i, j)) {
                colors[i] = j;
                break;
            }
        }
    }
}

// Function to print the assigned colors of vertices
void printColors() {
    printf("Vertex\tColor\n");
    for (int i = 0; i < VERTICES; i++)
        printf("%d\t%d\n", i, colors[i]);
}

// Driver function
int main() {
    // Initialize the input graph
    int graph[VERTICES][VERTICES] = {{0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
                                     {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                                     {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
                                     {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                                     {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
                                     {1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                                     {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                                     {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                                     {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                                     {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}};

    // Assign colors to vertices of the graph
    colorGraph();

    // Print the assigned colors of vertices
    printColors();

    return 0;
}
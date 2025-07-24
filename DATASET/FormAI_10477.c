//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include <stdio.h>

// Define the maximum number of vertices 
#define MAX_VERTICES 50
// Define the maximum number of colors 
#define MAX_COLORS 10

// Required function to solve graph coloring problem 
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int numColors) {

    // Define an array to store the colors assigned to each vertex
    int colors[MAX_VERTICES];

    // Initialize all vertices as uncolored and assign -1 as their color
    for (int i = 0; i < numVertices; i++) {
        colors[i] = -1;
    }

    // Color the first vertex with the first color
    colors[0] = 0;

    // Boolean array to store the available colors (true/false)
    int availableColors[MAX_COLORS];

    // Initially, all colors are available for each vertex
    for (int i = 0; i < numColors; i++) {
        availableColors[i] = 1;
    }

    // Assign colors to the remaining vertices
    for (int i = 1; i < numVertices; i++) {

        // Mark all the colors that are not available to this vertex
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] && colors[j] != -1) {
                availableColors[colors[j]] = 0;
            }
        }

        // Choose the first available color
        int chosenColor = -1;
        for (int j = 0; j < numColors; j++) {
            if (availableColors[j]) {
                chosenColor = j;
                break;
            }
        }

        // Assign the chosen color to the vertex
        colors[i] = chosenColor;

        // Reset the available colors for the next vertex
        for (int j = 0; j < numColors; j++) {
            availableColors[j] = 1;
        }
    }

    // Print the colors assigned to each vertex
    printf("Vertex   Color\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d        %d\n", i, colors[i]);
    }
}

int main() {
    // Define the adjacency matrix for a sample graph
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 0},
                                             {1, 1, 0, 1, 1},
                                             {0, 1, 1, 0, 1},
                                             {0, 0, 1, 1, 0}};

    // Define the number of vertices and colors
    int numVertices = 5;
    int numColors = 3;

    // Call the graph coloring function
    graphColoring(graph, numVertices, numColors);

    return 0;
}
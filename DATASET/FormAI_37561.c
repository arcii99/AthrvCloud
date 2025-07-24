//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
#include <stdio.h>

#define VERTICES 5         // Assuming we have five vertices in the graph

int main() {
    int graph[VERTICES][VERTICES] = {{0, 1, 1, 0, 1},
                                      {1, 0, 1, 1, 0},
                                      {1, 1, 0, 1, 0},
                                      {0, 1, 1, 0, 1},
                                      {1, 0, 0, 1, 0}};  // Example adjacency matrix of the graph
              
    int colors[VERTICES];   // Contains the color of the vertices
    int numColors = 3;      // Number of colors available.
                            // According to the requirement we've been given, vertices can only have 3 colors.

    // Assign the first vertex to the first color
    colors[0] = 1;

    // Assign 0 to all the remaining vertices (means they have not been colored yet)
    for(int i = 1; i < VERTICES; i++) {
        colors[i] = 0;
    }

    // Start assigning colors to the remaining uncolored vertices
    for(int i = 1; i < VERTICES; i++) {
        int availableColors[numColors + 1];

        // Reset the available colors array every time
        for(int j = 1; j <= numColors; j++) {
            availableColors[j] = 1;
        }

        // Loop through the nearby vertices of the vertex 'i'
        for(int j = 0; j < i; j++) {
            // Check if vertex 'j' is an adjacent vertex of vertex 'i'
            if(graph[i][j] == 1) {
                // If yes, mark its color as unavailable
                int color = colors[j];
                availableColors[color] = 0;
            }
        }

        // Choose the first available color from the available colors list
        for(int j = 1; j <= numColors; j++) {
            if(availableColors[j] == 1) {
                colors[i] = j;
                break;
            }
        }
    }

    // Print the final color assignment of the vertices
    for(int i = 0; i < VERTICES; i++) {
        printf("Vertex %d is assigned Color %d \n", i+1, colors[i]);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define VERTICES 6  // Number of vertices in the graph
#define COLORS 3    // Number of colors to use in coloring the vertices

// Function to check if a given vertex can be colored with a given color
int isSafe(int vertex, int color, int graph[][VERTICES], int colorAssignment[])
{
    for (int i = 0; i < VERTICES; i++) {
        if (graph[vertex][i] && colorAssignment[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the graph coloring problem
void graphColoring(int graph[][VERTICES], int colorAssignment[])
{
    #pragma omp parallel for
    for (int vertex = 0; vertex < VERTICES; vertex++) {
        if (colorAssignment[vertex] != 0) {
            continue;
        }

        // Try different colors for the current vertex
        for (int color = 1; color <= COLORS; color++) {
            if (isSafe(vertex, color, graph, colorAssignment)) {
                colorAssignment[vertex] = color;
                graphColoring(graph, colorAssignment);
                colorAssignment[vertex] = 0;
            }
        }
        return;
    }
    
    // Print the color assignment for each vertex
    printf("Vertex \t Color\n");
    for (int i = 0; i < VERTICES; i++) {
        printf("%d \t %d\n", i, colorAssignment[i]);
    }
}

int main()
{
    int graph[VERTICES][VERTICES] = {
        {0, 1, 0, 1, 0, 0},   // Vertex 0 is connected to vertices 1 and 3
        {1, 0, 1, 1, 0, 0},   // Vertex 1 is connected to vertices 0, 2 and 3
        {0, 1, 0, 1, 1, 1},   // Vertex 2 is connected to vertices 1, 3, 4 and 5
        {1, 1, 1, 0, 1, 0},   // Vertex 3 is connected to vertices 0, 1, 2 and 4
        {0, 0, 1, 1, 0, 1},   // Vertex 4 is connected to vertices 2 and 3
        {0, 0, 1, 0, 1, 0}    // Vertex 5 is connected to vertices 2 and 4
    };
    int colorAssignment[VERTICES] = {0};
    
    printf("Coloring the vertices in the graph...\n");
    graphColoring(graph, colorAssignment);
    
    return 0;
}
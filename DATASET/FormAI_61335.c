//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the maximum number of colors
#define MAX_COLORS 10

// Define a boolean data type
typedef enum { false, true } bool;

// Graph data structure
struct Graph {
    int num_vertices;
    int edges[MAX_VERTICES][MAX_VERTICES];
};

// Graph coloring function
bool graphColoring(struct Graph *g, int numColors, int color[]) {
    // Initialize all vertices as uncolored
    for (int i = 0; i < g->num_vertices; i++) {
        color[i] = 0;
    }
    // Color the first vertex with the first color
    color[0] = 1;
    // Initialize the remaining vertices as unvisited
    bool visited[g->num_vertices];
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = false;
    }
    // Visit each vertex in turn and color it with the first legal color
    for (int i = 1; i < g->num_vertices; i++) {
        visited[i - 1] = true;
        for (int j = 0; j < g->num_vertices; j++) {
            if (g->edges[i][j] && visited[j] && color[j] == color[i - 1]) {
                color[i] = (color[i - 1] % numColors) + 1;
                break;
            }
        }
        // If no legal color was found, return false
        if (color[i] == 0) {
            return false;
        }
    }
    // If all vertices were successfully colored, return true
    return true;
}

int main() {
    // Create a graph with 5 vertices and 6 edges
    struct Graph g = {
        .num_vertices = 5,
        .edges = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 1, 0},
            {1, 1, 0, 1, 1},
            {0, 1, 1, 0, 1},
            {0, 0, 1, 1, 0}
        }
    };
    // Choose the number of colors to use
    int numColors = 3;
    // Create an array to store the colors of each vertex
    int color[g.num_vertices];
    if (graphColoring(&g, numColors, color)) {
        printf("The graph was successfully colored with %d colors:\n", numColors);
        for (int i = 0; i < g.num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } else {
        printf("The graph could not be colored with %d colors.\n", numColors);
    }
    return 0;
}
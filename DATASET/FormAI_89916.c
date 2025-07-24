//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define the adjacency matrix to store the graph
int adjMat[MAX_VERTICES][MAX_VERTICES];

// Define the color array to keep track of the colors assigned to each vertex
int colors[MAX_VERTICES];

// Define the function to check if two vertices can have the same color
bool can_color_vertex(int vertex, int c) {

    for(int i=0; i<MAX_VERTICES; i++) {
        if(adjMat[vertex][i] && colors[i] == c) {
            return false;
        }
    }

    return true;
}

// Define the recursive function to color the graph
bool color_graph_rec(int vertex, int num_vertices, int num_colors) {

    if(vertex == num_vertices) {
        return true; // Graph fully colored!
    }

    for(int i=1; i<=num_colors; i++) {
        if(can_color_vertex(vertex, i)) {
            colors[vertex] = i;
            if(color_graph_rec(vertex+1, num_vertices, num_colors)) {
                return true; // Success!
            }
            colors[vertex] = 0;
        }
    }

    return false; // No solution possible!
}

// Define the function to call the graph coloring algorithm
void color_graph(int num_vertices, int num_colors) {

    if(color_graph_rec(0, num_vertices, num_colors)) {
        printf("Solution found!\n");
        for(int i=0; i<num_vertices; i++) {
            printf("Vertex %d colored with color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution possible.\n");
    }
}

int main() {

    // Initialize the adjacency matrix
    for(int i=0; i<MAX_VERTICES; i++) {
        for(int j=0; j<MAX_VERTICES; j++) {
            adjMat[i][j] = 0;
        }
    }

    // Define the graph to be colored
    adjMat[0][1] = adjMat[1][0] = 1;
    adjMat[0][3] = adjMat[3][0] = 1;
    adjMat[1][2] = adjMat[2][1] = 1;
    adjMat[1][4] = adjMat[4][1] = 1;
    adjMat[2][5] = adjMat[5][2] = 1;
    adjMat[3][4] = adjMat[4][3] = 1;
    adjMat[4][5] = adjMat[5][4] = 1;
    adjMat[5][6] = adjMat[6][5] = 1;

    // Call the graph coloring algorithm
    color_graph(7, 3); // 7 vertices and 3 colors

    return 0;
}
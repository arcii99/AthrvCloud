//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix representation of the graph
int colors[MAX_VERTICES] = {0}; // Array to store the colors assigned to each vertex

bool can_color_node(int node, int color) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[node][i] == 1 && colors[i] == color) {
            return false; // If there is a neighboring node with this color already assigned, we can't use it
        }
    }
    return true;
}

bool color_graph(int num_vertices, int num_colors) {
    if (num_vertices == 0) {
        return true; // Base case: we have successfully assigned a color to all vertices
    }

    for (int i = 1; i <= num_colors; i++) { // Try assigning each possible color to the next vertex
        if (can_color_node(MAX_VERTICES - num_vertices, i)) {
            colors[MAX_VERTICES - num_vertices] = i; // Assign the color
            if (color_graph(num_vertices - 1, num_colors)) {
                return true; // If we find a valid color assignment, we're done
            }
            // Otherwise, backtrack and try a different color
            colors[MAX_VERTICES - num_vertices] = 0;
        }
    }

    return false; // If we've tried all possible colors and can't find a valid assignment, the graph can't be colored with this many colors
}

int main() {
    // We'll use a simple graph with 4 nodes and 5 edges to test the program
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    int num_colors = 3; // Try coloring the graph with 3 colors
    if (color_graph(4, num_colors)) {
        printf("The graph can be colored with %d colors:\n", num_colors);
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("Node %d: Color %d\n", i, colors[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define MAX_EDGES 15

// structure to define graph
struct Graph {
    int vertices;
    int edges;
    int matrix[MAX_VERTICES][MAX_VERTICES];
};

// function prototype to solve graph coloring problem
void graph_coloring(struct Graph *graph);

int main() {
    struct Graph graph = {5, 7, {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    }};
    
    graph_coloring(&graph);

    return 0;
}

// function to check if a vertex can be colored with a given color
bool is_safe(struct Graph *graph, int vertex, int color, int colors[]) {
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// function to assign colors to vertices recursively
bool assign_colors(struct Graph *graph, int vertex, int colors[], int num_colors) {
    // base case: all vertices have been colored
    if (vertex == graph->vertices) {
        return true;
    }
    
    // try assigning color to this vertex
    for (int i = 1; i <= num_colors; i++) {
        if (is_safe(graph, vertex, i, colors)) {
            colors[vertex] = i;
            if (assign_colors(graph, vertex+1, colors, num_colors)) {
                return true;
            }
            colors[vertex] = 0;
        }
    }
    
    return false;
}

// function to solve the Graph Coloring problem
void graph_coloring(struct Graph *graph) {
    int colors[MAX_VERTICES] = {0};
    int num_colors = 3; // maximum number of colors
    
    // try assigning colors to vertices recursively
    if (assign_colors(graph, 0, colors, num_colors)) {
        printf("Graph can be colored using %d colors.\n", num_colors);
        printf("The color assigned to each vertex is as follows:\n");
        for (int i = 0; i < graph->vertices; i++) {
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
        }
    } else {
        printf("Graph cannot be colored using %d colors.\n", num_colors);
    }
}
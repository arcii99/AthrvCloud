//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of vertices
#define MAX_VERTICES 100

// Defining a boolean data type
typedef enum {
    false,
    true
} bool;

// Defining Graph data structure
typedef struct {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function Prototype
bool is_valid_color(int color, int vertex, Graph *graph, int colors[]);
void print_colors(int colors[], int num_vertices);
bool graph_coloring_util(Graph *graph, int num_colors, int vertex, int colors[]);
bool graph_coloring(Graph *graph, int num_colors);

int main()
{
    // Creating a graph with 5 vertices
    Graph graph;
    graph.num_vertices = 5;
    int adj_matrix[5][5] = {
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };
    // copying the adjacency matrix to the graph structure
    for (int i = 0; i < graph.num_vertices; i++) {
        for (int j = 0; j < graph.num_vertices; j++) {
            graph.adj_matrix[i][j] = adj_matrix[i][j];
        }
    }

    // Coloring the graph with 3 colors
    int num_colors = 3;
    int result = graph_coloring(&graph, num_colors);

    // Checking if the Graph is colored 
    if (result) {
        printf("\nGraph can be colored with minimum %d colors\n\n", num_colors);
    } else {
        printf("\nGraph cannot be colored with %d colors\n\n", num_colors);
    }

    return 0;
}

// Function to check if a color can be assigned to a vertex
bool is_valid_color(int color, int vertex, Graph *graph, int colors[])
{
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[vertex][i] && color == colors[i]) {
            return false;
        }
    }
    return true;
}

// Function to print the colors assigned to the vertices
void print_colors(int colors[], int num_vertices)
{
    printf("\nVertex Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, colors[i]);
    }
    printf("\n");
}

// Recursive utility function to color the graph vertices
bool graph_coloring_util(Graph *graph, int num_colors, int vertex, int colors[])
{
    // if all vertices are assigned a color
    if (vertex == graph->num_vertices) {
        print_colors(colors, graph->num_vertices);
        return true;
    }

    // Checking all possible colors
    for (int color = 1; color <= num_colors; color++) {
        // if a color can be assigned to the current vertex
        if (is_valid_color(color, vertex, graph, colors)) {
            colors[vertex] = color;
            // Checking if it is possible to assign color to the next vertex
            if (graph_coloring_util(graph, num_colors, vertex + 1, colors)) {
                return true;
            }
            // if assigning the current color does not provide a solution
            colors[vertex] = 0;
        }
    }
    return false;
}

// Function to color the graph
bool graph_coloring(Graph *graph, int num_colors)
{
    int colors[MAX_VERTICES] = {0};
    return graph_coloring_util(graph, num_colors, 0, colors);
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Define Graph struct
typedef struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Define function to initialize graph
void initialize_graph(Graph *g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

// Define function to add edge to graph
void add_edge(Graph *g, int u, int v) {
    g->adj_matrix[u][v] = 1;
    g->adj_matrix[v][u] = 1;
}

// Define function to print graph
void print_graph(Graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Define function to check if vertex can be assigned a certain color
bool is_valid_color(Graph *g, int vertex, int color, int coloring[]) {
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->adj_matrix[vertex][i] == 1 && coloring[i] == color) {
            return false;
        }
    }
    return true;
}

// Define recursive function to solve graph coloring problem
bool graph_coloring_util(Graph *g, int num_colors, int vertex, int coloring[]) {
    // Base case: all vertices have been assigned a color
    if (vertex == g->num_vertices) {
        return true;
    }

    // Try each color for current vertex
    for (int i = 1; i <= num_colors; i++) {
        // Check if vertex can be assigned this color
        if (is_valid_color(g, vertex, i, coloring)) {
            coloring[vertex] = i;

            // Recurse to next vertex
            if (graph_coloring_util(g, num_colors, vertex + 1, coloring)) {
                return true;
            }

            // Backtrack if recursion failed
            coloring[vertex] = 0;
        }
    }

    // If no color can be assigned to vertex, return false
    return false;
}

// Define function to solve graph coloring problem
void graph_coloring(Graph *g, int num_colors) {
    int coloring[MAX_VERTICES] = {0};

    if (graph_coloring_util(g, num_colors, 0, coloring)) {
        // Print coloring
        printf("Solution: ");
        for (int i = 0; i < g->num_vertices; i++) {
            printf("%d ", coloring[i]);
        }
        printf("\n");
    } else {
        printf("No solution found.");
    }
}

// Main function for testing
int main() {
    // Initialize graph
    Graph g;
    initialize_graph(&g, 5);

    // Add edges to graph
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 4);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);

    // Print graph
    printf("Graph:\n");
    print_graph(&g);

    // Solve graph coloring problem with 3 colors
    printf("Coloring with 3 colors:\n");
    graph_coloring(&g, 3);

    // Solve graph coloring problem with 2 colors
    printf("Coloring with 2 colors:\n");
    graph_coloring(&g, 2);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10
#define MAX_EDGES 15

// Graph Data Structure
typedef struct {
    int num_vertices;
    int num_edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_color[MAX_VERTICES];
} Graph;

// Function to generate a random graph
void generate_graph(Graph* graph) {
    srand(time(NULL));
    graph->num_vertices = rand() % MAX_VERTICES + 1;
    graph->num_edges = rand() % MAX_EDGES + 1;

    // Initialize adjacency matrix
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }

    // Add random edges to the graph
    for (int i = 0; i < graph->num_edges; i++) {
        int vertex_1 = rand() % graph->num_vertices;
        int vertex_2 = rand() % graph->num_vertices;

        graph->adjacency_matrix[vertex_1][vertex_2] = 1;
        graph->adjacency_matrix[vertex_2][vertex_1] = 1;
    }
}

// Function to color the graph
void color_graph(Graph* graph) {
    int available_colors[MAX_VERTICES];

    // Initialize all colors as available
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->vertex_color[i] = -1;
        available_colors[i] = 1;
    }

    // Color the vertices
    for (int i = 0; i < graph->num_vertices; i++) {
        // Find first available color for the vertex
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] && graph->vertex_color[j] != -1) {
                available_colors[graph->vertex_color[j]] = 0;
            }
        }

        // Assign the available color to the vertex
        for (int j = 0; j < graph->num_vertices; j++) {
            if (available_colors[j]) {
                graph->vertex_color[i] = j;
                break;
            }
        }

        // Reset available colors for next vertex
        for (int j = 0; j < graph->num_vertices; j++) {
            if (graph->adjacency_matrix[i][j] && graph->vertex_color[j] != -1) {
                available_colors[graph->vertex_color[j]] = 1;
            }
        }
    }
}

int main() {
    Graph graph;

    // Generate a random graph
    generate_graph(&graph);

    // Color the graph
    color_graph(&graph);

    // Print the colored graph
    printf("Number of vertices: %d\n", graph.num_vertices);
    printf("Number of edges: %d\n", graph.num_edges);
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < graph.num_vertices; i++) {
        for (int j = 0; j < graph.num_vertices; j++) {
            printf("%d ", graph.adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    printf("Vertex Colors:\n");

    for (int i = 0; i < graph.num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, graph.vertex_color[i]);
    }

    return 0;
}
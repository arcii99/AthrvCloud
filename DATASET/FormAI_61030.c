//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Defining the maximum number of vertices and edges
#define MAX_VERTICES 100
#define MAX_EDGES 10000

// Creating a structure to hold information about edges
typedef struct {
    int vertex1;
    int vertex2;
} Edge;

// Creating a structure to hold information about vertices
typedef struct {
    int color;
    int num_edges;
    int edges[MAX_EDGES];
} Vertex;

// Creating an array of vertices and edges
Vertex vertices[MAX_VERTICES];
Edge edges[MAX_EDGES];

// Function to check if two vertices are adjacent
int areAdjacent(int vertex1, int vertex2) {
    for (int i = 0; i < vertices[vertex1].num_edges; i++) {
        if (vertices[vertex1].edges[i] == vertex2) {
            return 1;
        }
    }
    return 0;
}

// Function to determine if a vertex can be colored with a given color
int canColorVertex(int vertex, int color) {
    for (int i = 0; i < vertices[vertex].num_edges; i++) {
        if (vertices[vertices[vertex].edges[i]].color == color) {
            return 0;
        }
    }
    return 1;
}

// Function to color the graph
void colorGraph(int num_vertices, int num_colors) {
    // Start with a random vertex
    int current_vertex = rand() % num_vertices;

    // Color the starting vertex with the first color
    vertices[current_vertex].color = 1;

    // Iterate over all the remaining vertices
    for (int i = 1; i < num_vertices; i++) {
        int found_vertex = 0;

        // Try all the colors for the current vertex until it can be colored
        for (int j = 1; j <= num_colors; j++) {
            if (canColorVertex(current_vertex, j)) {
                vertices[current_vertex].color = j;
                found_vertex = 1;
                break;
            }
        }

        // If no color can be found for the current vertex, backtrack to the previous vertex and try again
        if (!found_vertex) {
            i -= 2;
            current_vertex = edges[i].vertex1;
            vertices[current_vertex].color = 0;
        }

        // Move on to the next vertex
        else {
            current_vertex = edges[i].vertex2;
        }
    }
}

// Function to print the graph
void printGraph(int num_vertices, int num_edges) {
    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < vertices[i].num_edges; j++) {
            printf("%d ", vertices[i].edges[j]);
        }
        printf("\n");
    }
}

// Function to print the colors of the vertices
void printColors(int num_vertices) {
    printf("Colors:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: %d\n", i, vertices[i].color);
    }
}

// Main function
int main() {
    int num_vertices, num_edges, num_colors;

    // Get user input for the number of vertices, edges, and colors
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    // Get user input for the edges
    printf("Enter the edges:\n");
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[i].vertex1, &edges[i].vertex2);
        vertices[edges[i].vertex1].edges[vertices[edges[i].vertex1].num_edges++] = edges[i].vertex2;
        vertices[edges[i].vertex2].edges[vertices[edges[i].vertex2].num_edges++] = edges[i].vertex1;
    }

    // Print the graph
    printGraph(num_vertices, num_edges);

    // Color the graph
    colorGraph(num_vertices, num_colors);

    // Print the colors of the vertices
    printColors(num_vertices);

    return 0;
}
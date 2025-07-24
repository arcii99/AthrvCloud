//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20
#define MAX_EDGES 100

// Graph struct
typedef struct {
    int vertices[MAX_VERTICES];
    int edges[MAX_EDGES][2];
    int num_edges;
} Graph;

// Function to add an edge to the graph
void add_edge(Graph *g, int u, int v) {
    g->edges[g->num_edges][0] = u;
    g->edges[g->num_edges][1] = v;
    g->num_edges++;
}

// Function to print the graph
void print_graph(Graph g) {
    for (int i = 0; i < g.num_edges; i++) {
        printf("(%d, %d) ", g.edges[i][0], g.edges[i][1]);
    }
    printf("\n");
}

// Function to color the vertices of the graph
void color_graph(Graph g, int num_colors) {
    int colors[MAX_VERTICES];
    int colored[MAX_VERTICES] = {0};

    // Initialize colors to -1
    for (int i = 0; i < MAX_VERTICES; i++) {
        colors[i] = -1;
    }

    // Color first vertex with first color
    colored[g.vertices[0]] = 1;
    colors[g.vertices[0]] = 0;

    // Color remaining vertices
    for (int i = 1; i < MAX_VERTICES; i++) {
        int vertex = g.vertices[i];
        int valid_color = 0;
        int j = 0;

        // Check for valid color for current vertex
        while (!valid_color) {
            int color = rand() % num_colors;
            valid_color = 1;

            // Check if any adjacent vertices have same color
            for (int k = 0; k < g.num_edges; k++) {
                int u = g.edges[k][0];
                int v = g.edges[k][1];
                if ((u == vertex && colored[v] && colors[v] == color) ||
                    (v == vertex && colored[u] && colors[u] == color)) {
                    valid_color = 0;
                    break;
                }
            }

            // If valid color found, color vertex
            if (valid_color) {
                colored[vertex] = 1;
                colors[vertex] = color;
            }

            // If all colors tried and none valid, backtrack
            if (j == num_colors - 1 && !valid_color) {
                j = 0;
                i = i - 1;
                colored[vertex] = 0;
                colors[vertex] = -1;
                if (i == 0) {
                    printf("Unable to color graph with %d colors.\n", num_colors);
                    return;
                }
                vertex = g.vertices[i];
            }
            j++;
        }
    }

    // Print colors of vertices
    printf("Vertices colored with the following colors:\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d: %d\n", g.vertices[i], colors[g.vertices[i]]);
    }
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Initialize graph
    Graph g;
    g.num_edges = 0;

    // Add vertices
    for (int i = 0; i < MAX_VERTICES; i++) {
        g.vertices[i] = i;
    }

    // Add edges
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 4);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 4, 5);

    // Print graph
    printf("Graph:\n");
    print_graph(g);

    // Color graph with 3 colors
    printf("Coloring graph with 3 colors...\n");
    color_graph(g, 3);

    return 0;
}
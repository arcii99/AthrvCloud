//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include<stdio.h>

// Defining the maximum number of vertices the graph can have
#define MAX_VERTICES 20

// Struct to represent a graph
struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph with no edges
void initialize_graph(struct Graph* g) {
    int i, j;
    g->num_vertices = 0;
    for (i=0; i<MAX_VERTICES; i++) {
        for (j=0; j<MAX_VERTICES; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

// Function to add a vertex to the graph
void add_vertex(struct Graph* g) {
    int i;
    if (g->num_vertices == MAX_VERTICES) {
        printf("Error: Maximum number of vertices reached\n");
        return;
    }
    g->num_vertices++;
    for (i=0; i<g->num_vertices; i++) {
        g->adj_matrix[i][g->num_vertices-1] = 0;
        g->adj_matrix[g->num_vertices-1][i] = 0;
    }
}

// Function to add an edge to the graph
void add_edge(struct Graph* g, int source, int destination) {
    if (source >= g->num_vertices || destination >= g->num_vertices) {
        printf("Error: Invalid edge\n");
        return;
    }
    g->adj_matrix[source][destination] = 1;
    g->adj_matrix[destination][source] = 1;
}

// Function that colors the graph with at most k different colors
void color_graph(struct Graph* g, int k) {
    int i, j, v;
    int color[MAX_VERTICES];
    for (i=0; i<g->num_vertices; i++) {
        color[i] = 0;
    }
    for (v=0; v<g->num_vertices; v++) {
        int available[k+1];
        for (i=0; i<=k; i++) {
            available[i] = 1;
        }
        for (i=0; i<g->num_vertices; i++) {
            if (g->adj_matrix[v][i] && color[i] != 0) {
                available[color[i]] = 0;
            }
        }
        for (i=1; i<=k; i++) {
            if (available[i]) {
                color[v] = i;
                break;
            }
        }
    }
    printf("Coloring of the graph with at most %d different colors:\n", k);
    for (i=0; i<g->num_vertices; i++) {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

int main() {
    struct Graph g;
    int i;
    initialize_graph(&g);

    // Add vertices to the graph
    for (i=0; i<5; i++) {
        add_vertex(&g);
    }

    // Add edges to the graph
    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 3);
    add_edge(&g, 3, 4);
    add_edge(&g, 0, 3);
    add_edge(&g, 1, 4);

    // Color the graph with at most 3 different colors
    color_graph(&g, 3);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

/* Graph structure */
typedef struct Graph {
    int num_vertices;
    int num_edges;
    int edges[MAX_VERTICES][MAX_VERTICES];
} Graph;

/* Function prototypes */
void initialize_graph(Graph* G);
void add_vertex(Graph* G, int vertex);
void add_edge(Graph* G, int vertex_from, int vertex_to, int weight);
void display_graph(Graph* G);

/* Main function */
int main() {
    Graph G;
    initialize_graph(&G);
    
    add_vertex(&G, 0);
    add_vertex(&G, 1);
    add_vertex(&G, 2);
    add_vertex(&G, 3);
    add_vertex(&G, 4);
    add_vertex(&G, 5);
    
    add_edge(&G, 0, 1, 5);
    add_edge(&G, 0, 2, 3);
    add_edge(&G, 1, 2, 4);
    add_edge(&G, 1, 3, 9);
    add_edge(&G, 2, 3, 5);
    add_edge(&G, 3, 5, 1);
    add_edge(&G, 4, 5, 3);

    display_graph(&G);
    
    return 0;
}

/* Function to initialize Graph */
void initialize_graph(Graph* G) {
    int i, j;
    
    G->num_vertices = 0;
    G->num_edges = 0;
    
    for (i = 0; i < MAX_VERTICES; ++i) {
        for (j = 0; j < MAX_VERTICES; ++j) {
            G->edges[i][j] = 0;
        }
    }
}

/* Function to add vertex in Graph */
void add_vertex(Graph* G, int vertex) {
    if (G->num_vertices == MAX_VERTICES) {
        printf("Graph is full.\n");
        return;
    }
    
    G->num_vertices++;
}

/* Function to add edge in Graph */
void add_edge(Graph* G, int vertex_from, int vertex_to, int weight) {
    if (vertex_from < 0 || vertex_from >= G->num_vertices) {
        printf("Invalid vertex: %d\n", vertex_from);
        return;
    }
    
    if (vertex_to < 0 || vertex_to >= G->num_vertices) {
        printf("Invalid vertex: %d\n", vertex_to);
        return;
    }
    
    G->edges[vertex_from][vertex_to] = weight;
    G->edges[vertex_to][vertex_from] = weight;
    G->num_edges++;
}

/* Function to display graph */
void display_graph(Graph* G) {
    int i, j;
    
    printf("Number of vertices: %d\n", G->num_vertices);
    printf("Number of edges: %d\n", G->num_edges);
    
    for (i = 0; i < G->num_vertices; ++i) {
        printf("Vertex %d is connected to:\n", i);
        
        for (j = 0; j < G->num_vertices; ++j) {
            if (G->edges[i][j] != 0) {
                printf("\tVertex %d (Weight: %d)\n", j, G->edges[i][j]);
            }
        }
    }
}
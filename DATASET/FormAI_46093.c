//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices
#define MAX_VERTICES 100

// Define the maximum number of edges
#define MAX_EDGES 1000

// Define a structure for a vertex
typedef struct Vertex {
    int id; // Vertex ID
    bool visited; // Visited flag
} Vertex;

// Define an edge structure
typedef struct Edge {
    int src; // Source vertex
    int dest; // Destination vertex
    int weight; // Edge weight
} Edge;

// Define a graph structure
typedef struct Graph {
    Vertex vertices[MAX_VERTICES]; // Array of vertices
    Edge edges[MAX_EDGES]; // Array of edges
    int num_vertices; // Number of vertices
    int num_edges; // Number of edges
} Graph;

// Function prototypes
void init_graph(Graph *graph);
void add_vertex(Graph *graph, int id);
void add_edge(Graph *graph, int src, int dest, int weight);
void print_graph(Graph *graph);

int main() {
    Graph graph;
    init_graph(&graph);

    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);

    add_edge(&graph, 1, 2, 3);
    add_edge(&graph, 2, 3, 4);
    add_edge(&graph, 3, 1, 5);

    print_graph(&graph);

    return 0;
}

// Function to initialize a graph
void init_graph(Graph *graph) {
    graph->num_vertices = 0;
    graph->num_edges = 0;

    for(int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].id = 0;
        graph->vertices[i].visited = false;
    }

    for(int i = 0; i < MAX_EDGES; i++) {
        graph->edges[i].src = 0;
        graph->edges[i].dest = 0;
        graph->edges[i].weight = 0;
    }
}

// Function to add a vertex to the graph
void add_vertex(Graph *graph, int id) {
    graph->vertices[graph->num_vertices].id = id;
    graph->num_vertices++;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int src, int dest, int weight) {
    graph->edges[graph->num_edges].src = src;
    graph->edges[graph->num_edges].dest = dest;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

// Function to print the graph
void print_graph(Graph *graph) {
    printf("Vertices:\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        printf("%d ", graph->vertices[i].id);
    }
    printf("\n");

    printf("Edges:\n");
    for(int i = 0; i < graph->num_edges; i++) {
        printf("(%d, %d, %d) ", graph->edges[i].src, graph->edges[i].dest, graph->edges[i].weight);
    }
}
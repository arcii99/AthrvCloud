//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include <stdio.h>

// define constants for the maximum number of vertices and edges
#define MAX_VERTICES 50
#define MAX_EDGES 50

// define a struct to represent the graph
typedef struct {
    int num_vertices; // number of vertices
    int num_edges; // number of edges
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]; // matrix to represent edge connections
} Graph;

// function to initialize the graph
void initialize_graph(Graph* graph) {
    int i, j;
    graph->num_vertices = 0;
    graph->num_edges = 0;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
}

// function to add a vertex to the graph
void add_vertex(Graph* graph) {
    int i;
    // check if there is space to add another vertex
    if (graph->num_vertices == MAX_VERTICES) {
        printf("Error: graph is full.\n");
        return;
    }
    // increase the number of vertices and initialize the row and column for the new vertex
    graph->num_vertices++;
    for (i = 0; i < graph->num_vertices; i++) {
        graph->adjacency_matrix[i][graph->num_vertices-1] = 0;
        graph->adjacency_matrix[graph->num_vertices-1][i] = 0;
    }
}

// function to add an edge between two vertices in the graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
    // check if the vertices are valid
    if (vertex1 >= graph->num_vertices || vertex2 >= graph->num_vertices || vertex1 < 0 || vertex2 < 0) {
        printf("Error: invalid vertices.\n");
        return;
    }
    // update the adjacency matrix to represent the edge
    graph->adjacency_matrix[vertex1][vertex2] = 1;
    graph->adjacency_matrix[vertex2][vertex1] = 1;
    graph->num_edges++;
}

// function to print the graph
void print_graph(Graph* graph) {
    int i, j;
    printf("Graph:\n");
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize the graph
    Graph graph;
    initialize_graph(&graph);

    // add vertices to the graph
    add_vertex(&graph);
    add_vertex(&graph);
    add_vertex(&graph);

    // add edges to the graph
    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);

    // print the graph
    print_graph(&graph);

    return 0;
}
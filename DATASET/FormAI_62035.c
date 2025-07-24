//FormAI DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>

// define the maximum number of vertices
#define MAX_VERTICES 10

// create a struct to store information about the edges
typedef struct {
    int v1; // starting vertex of the edge
    int v2; // ending vertex of the edge
    int weight; // weight of the edge
} Edge;

// create a struct to represent a graph
typedef struct {
    int num_vertices; // number of vertices in the graph
    int num_edges; // number of edges in the graph
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to store the graph
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2]; // array to store the edges
} Graph;

// function to add an edge to the graph
void add_edge(Graph* graph, int v1, int v2, int weight) {
    graph->adjacency_matrix[v1][v2] = weight;
    graph->adjacency_matrix[v2][v1] = weight;
    graph->num_edges++;
    Edge new_edge = {v1, v2, weight};
    graph->edges[graph->num_edges-1] = new_edge;
}

// function to print the graph
void print_graph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nEdges:\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("(%d,%d) weight=%d\n", graph->edges[i].v1, graph->edges[i].v2, graph->edges[i].weight);
    }
}

int main() {
    // create a new graph
    Graph my_graph = {0, 0};
    
    // add some edges to the graph
    add_edge(&my_graph, 0, 1, 5);
    add_edge(&my_graph, 1, 2, 7);
    add_edge(&my_graph, 2, 3, 3);
    add_edge(&my_graph, 3, 0, 2);
    add_edge(&my_graph, 1, 3, 9);
    
    // print the graph
    print_graph(&my_graph);
    
    return 0;
}
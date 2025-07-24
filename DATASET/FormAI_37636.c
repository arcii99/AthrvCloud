//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

/* This is the structure to represent a vertex */
typedef struct {
    int id;  // vertex's id
    int x;   // x coordinate of vertex
    int y;   // y coordinate of vertex
} Vertex;

/* This is the structure to represent an edge */
typedef struct {
    int u;  // id of one vertex
    int v;  // id of another vertex
} Edge;

/* This is the structure to represent a graph */
typedef struct {
    Vertex vertices[MAX_VERTICES];  // array of vertices
    Edge edges[MAX_VERTICES];       // array of edges
    int num_vertices;               // number of vertices in graph
    int num_edges;                  // number of edges in graph
} Graph;

/* This function adds a vertex to the graph */
void add_vertex(Graph *graph, Vertex v) {
    graph->vertices[graph->num_vertices++] = v;
}

/* This function adds an edge to the graph */
void add_edge(Graph *graph, Edge e) {
    graph->edges[graph->num_edges++] = e;
}

/* This function generates a random graph */
Graph generate_random_graph() {
    Graph graph = {0};
    int num_vertices = rand() % MAX_VERTICES;
    for (int i = 0; i < num_vertices; i++) {
        Vertex v = {i, rand() % 100, rand() % 100};
        add_vertex(&graph, v);
    }
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i+1; j < num_vertices; j++) {
            if (rand() % 2 == 0) {
                Edge e = {i, j};
                add_edge(&graph, e);
            }
        }
    }
    return graph;
}

/* This function prints the graph */
void print_graph(Graph graph) {
    printf("Vertices:\n");
    for (int i = 0; i < graph.num_vertices; i++) {
        printf("%d (%d, %d)\n", graph.vertices[i].id, 
               graph.vertices[i].x, graph.vertices[i].y);
    }
    printf("Edges:\n");
    for (int i = 0; i < graph.num_edges; i++) {
        printf("(%d, %d)\n", graph.edges[i].u, graph.edges[i].v);
    }
}

/* Main function */
int main() {
    srand(time(NULL));
    Graph graph = generate_random_graph();
    print_graph(graph);
    return 0;
}
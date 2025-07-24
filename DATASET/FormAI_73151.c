//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int weight;
    int start_vertex;
    int end_vertex;
} Edge;

typedef struct Graph {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_VERTICES];
} Graph;

void printGraph(Graph graph) {
    int i;

    printf("Number of vertices: %d\n", graph.num_vertices);
    printf("Number of edges: %d\n", graph.num_edges);

    for (i = 0; i < graph.num_edges; i++) {
        printf("Edge %d: %d --(%d)-- %d\n", i+1, graph.edges[i].start_vertex, graph.edges[i].weight, graph.edges[i].end_vertex);
    }
}

int main() {
    Graph graph;
    int i;

    graph.num_vertices = 5;
    graph.num_edges = 7;

    graph.edges[0].start_vertex = 1;
    graph.edges[0].end_vertex = 2;
    graph.edges[0].weight = 1;

    graph.edges[1].start_vertex = 1;
    graph.edges[1].end_vertex = 3;
    graph.edges[1].weight = 3;

    graph.edges[2].start_vertex = 2;
    graph.edges[2].end_vertex = 3;
    graph.edges[2].weight = 1;

    graph.edges[3].start_vertex = 2;
    graph.edges[3].end_vertex = 4;
    graph.edges[3].weight = 5;

    graph.edges[4].start_vertex = 2;
    graph.edges[4].end_vertex = 5;
    graph.edges[4].weight = 5;

    graph.edges[5].start_vertex = 3;
    graph.edges[5].end_vertex = 4;
    graph.edges[5].weight = 4;

    graph.edges[6].start_vertex = 4;
    graph.edges[6].end_vertex = 5;
    graph.edges[6].weight = 2;

    printGraph(graph);

    return 0;
}
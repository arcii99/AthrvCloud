//FormAI DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

typedef struct Graph {
    int num_vertices;
    int num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* createGraph(int num_vertices, int num_edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    return graph;
}

void addEdge(Graph* graph, int from, int to, int weight) {
    graph->edges[graph->num_edges].from = from;
    graph->edges[graph->num_edges].to = to;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void printGraph(Graph* graph) {
    for(int i = 0; i < graph->num_edges; i++) {
        printf("(%d, %d, %d)\n", graph->edges[i].from, graph->edges[i].to, graph->edges[i].weight);
    }
}

int main() {
    Graph* graph = createGraph(5, 7);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 4, 4);

    printGraph(graph);
    return 0;
}
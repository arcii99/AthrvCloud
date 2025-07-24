//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

#define MAX_VERTICES 10

// edge struct to represent edges in the graph
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

// struct to represent the graph
typedef struct {
    int num_vertices;
    int edge_count;
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
} Graph;

// function to add edge to the graph
void addEdge(Graph* graph, int source, int destination, int weight) {
    graph->edges[graph->edge_count].source = source;
    graph->edges[graph->edge_count].destination = destination;
    graph->edges[graph->edge_count].weight = weight;
    graph->edge_count++;
}

// function to print the graph
void printGraph(Graph* graph) {
    printf("Vertex\t\tConnected to\n");
    printf("------\t\t------------\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d\t\t", i);
        for (int j = 0; j < graph->edge_count; j++) {
            if (graph->edges[j].source == i) {
                printf("%d (w=%d) ", graph->edges[j].destination, graph->edges[j].weight);
            } else if (graph->edges[j].destination == i) {
                printf("%d (w=%d) ", graph->edges[j].source, graph->edges[j].weight);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    graph.num_vertices = 5;
    graph.edge_count = 0;

    // add edges to the graph
    addEdge(&graph, 0, 1, 5);
    addEdge(&graph, 0, 2, 2);
    addEdge(&graph, 1, 2, 3);
    addEdge(&graph, 1, 3, 6);
    addEdge(&graph, 2, 3, 2);
    addEdge(&graph, 2, 4, 4);
    addEdge(&graph, 3, 4, 5);

    // print the graph
    printGraph(&graph);

    return 0;
}
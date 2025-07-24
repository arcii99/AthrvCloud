//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
// This program demonstrates a unique way to represent a graph in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix to store edges
    int n; //number of vertices
} Graph;

Graph create_graph(int n) {
    Graph graph;
    graph.n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph.adj[i][j] = 0; //initialize adjacency matrix to 0
        }
    }
    return graph;
}

void add_edge(Graph *graph, int u, int v, int w) { //function to add edge
    graph->adj[u][v] = w;
}

void print_graph(Graph graph) { //function to print the graph
    printf("Graph:\n");
    for (int i = 0; i < graph.n; i++) {
        for (int j = 0; j < graph.n; j++) {
            printf("%d ", graph.adj[i][j]); //print the adjacency matrix
        }
        printf("\n");
    }
}

int main() {
    Graph graph = create_graph(5);
    add_edge(&graph, 0, 1, 5);
    add_edge(&graph, 1, 2, 3);
    add_edge(&graph, 2, 3, 2);
    add_edge(&graph, 3, 4, 1);
    add_edge(&graph, 4, 0, 4);
    print_graph(graph);
    return 0;
}
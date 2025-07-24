//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
struct Graph
{
    int V; // Number of vertices
    int E; // Number of edges
    int **adj; // Pointer to 2D array to store edges
};

// Function to create graph
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->adj = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0; // Initialize all edges as 0
        }
    }
    return graph;
}

// Function to add edge to graph
void addEdge(struct Graph *graph, int u, int v)
{
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

// Function to print graph
void printGraph(struct Graph *graph)
{
    printf("The graph is:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Create a graph
    struct Graph *graph = createGraph(5, 6);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);

    // Print the graph
    printGraph(graph);

    return 0;
}
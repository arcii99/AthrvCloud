//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50

typedef struct Edge {
    int sourceVertex;
    int destinationVertex;
    int weight;
} Edge;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge edgeList[MAX_EDGES];
} Graph;

void initializeGraph(Graph *graph) {
    graph->numVertices = 0;
    graph->numEdges = 0;
}

void addVertex(Graph *graph) {
    if (graph->numVertices < MAX_VERTICES) {
        graph->numVertices++;
    } else {
        printf("Graph has reached maximum number of vertices.\n");
    }
}

void addEdge(Graph *graph, int sourceVertex, int destinationVertex, int weight) {
    if (graph->numEdges < MAX_EDGES) {
        graph->edgeList[graph->numEdges].sourceVertex = sourceVertex;
        graph->edgeList[graph->numEdges].destinationVertex = destinationVertex;
        graph->edgeList[graph->numEdges].weight = weight;
        graph->numEdges++;
    } else {
        printf("Graph has reached maximum number of edges.\n");
    }
}

void *printGraph(void *args) {
    Graph *graph = (Graph *)args;

    printf("Number of vertices: %d\n", graph->numVertices);
    printf("Number of edges: %d\n", graph->numEdges);
    printf("Edge List:\n");

    for (int i = 0; i < graph->numEdges; i++) {
        printf("(%d, %d) weight: %d\n", 
               graph->edgeList[i].sourceVertex, 
               graph->edgeList[i].destinationVertex, 
               graph->edgeList[i].weight);
    }

    pthread_exit(NULL);
}

int main() {
    Graph graph;
    initializeGraph(&graph);

    // Add some vertices to the graph
    addVertex(&graph);
    addVertex(&graph);
    addVertex(&graph);

    // Add some edges to the graph
    addEdge(&graph, 1, 2, 10);
    addEdge(&graph, 1, 3, 15);
    addEdge(&graph, 2, 3, 20);

    // Print the graph using a separate thread
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, printGraph, (void *)&graph);
    if (rc) {
        printf("Error: pthread_create() returned %d\n", rc);
        exit(-1);
    }

    pthread_join(thread, NULL);

    return 0;
}
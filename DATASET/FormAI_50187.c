//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
// Hi there! I'm a graph representation program, and I'm here to make you happy! 
// Let's get started by creating a cheerful graph!
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

// Here we declare our struct for a graph.
struct Graph {
    int vertices[MAX_VERTICES];
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numOfVertices;
};

// This function initializes our empty graph with no vertices or edges.
void initGraph(struct Graph* graph) {
    for(int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i] = 0;
        for(int j = 0; j < MAX_VERTICES; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
    graph->numOfVertices = 0;
}

// This function adds a vertex to our graph.
void addVertex(struct Graph* graph, int vertex) {
    graph->vertices[graph->numOfVertices] = vertex;
    graph->numOfVertices++;
}

// This function adds an edge between two vertices.
void addEdge(struct Graph* graph, int vertex1, int vertex2) {
    graph->adjacencyMatrix[vertex1][vertex2] = 1;
    graph->adjacencyMatrix[vertex2][vertex1] = 1;
}

// This function prints out the vertices and edges of our graph.
void printGraph(struct Graph* graph) {
    printf("Vertices: ");
    for(int i = 0; i < graph->numOfVertices; i++) {
        printf("%d ", graph->vertices[i]);
    }
    printf("\n");
    printf("Edges: \n");
    for(int i = 0; i < graph->numOfVertices; i++) {
        for(int j = i; j < graph->numOfVertices; j++) {
            if(graph->adjacencyMatrix[i][j] == 1) {
                printf("%d - %d\n", graph->vertices[i], graph->vertices[j]);
            }
        }
    }
}

// Hooray! Now, we can create our beautiful graph and spread happiness.
int main() {
    struct Graph myGraph;
    initGraph(&myGraph);
    
    addVertex(&myGraph, 1);
    addVertex(&myGraph, 2);
    addVertex(&myGraph, 3);
    addVertex(&myGraph, 4);
    addVertex(&myGraph, 5);
    
    addEdge(&myGraph, 1, 2);
    addEdge(&myGraph, 1, 3);
    addEdge(&myGraph, 2, 4);
    addEdge(&myGraph, 3, 5);
    
    printf("Hello! Here is our cheerful graph: \n");
    printGraph(&myGraph);
    
    printf("Isn't it just lovely?\n");
    return 0;
}
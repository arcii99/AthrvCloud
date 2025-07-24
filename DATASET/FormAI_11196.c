//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Graph {
    int size;
    struct Node** adjList;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int size) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->size = size;
    newGraph->adjList = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Adds an undirected edge to the graph.
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    // Prints the adjacency list of the graph.
    for (int i = 0; i < graph->size; i++) {
        struct Node* currNode = graph->adjList[i];
        printf("\nAdjacency list of vertex %d:", i);
        while (currNode != NULL) {
            printf(" -> %d", currNode->value);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    printGraph(graph);
    return 0;
}
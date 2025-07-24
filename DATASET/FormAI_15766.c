//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Defining struct for adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Defining struct for adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Defining struct for graph (V vertices and adjacency list)
struct Graph {
    int V;
    struct AdjList* array;
};

// Creating new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Creating new graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocating space for adjacency list
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initializing adjacency list nodes
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Adding edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Adding edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Adding edge from dest to src
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Printing graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct AdjListNode* ptr = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head", i);

        while (ptr) {
            printf(" -> %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    // Creating graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Adding edges to graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Printing graph
    printGraph(graph);

    return 0;
}
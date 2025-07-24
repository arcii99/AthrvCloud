//FormAI DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Adjacency list node
typedef struct Node {
    int dest;
    struct Node* next;
} Node;

// Adjacency list
typedef struct List {
    Node* head;
} List;

// Graph structure
typedef struct Graph {
    int V; // Number of vertices
    List* array;
} Graph;

// Create a new node
Node* newNode(int dest) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// Create a new graph
Graph* newGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    // Create an array of adjacency lists
    graph->array = (List*)malloc(V * sizeof(List));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* new_node = newNode(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    // Add edge from dest to src
    new_node = newNode(src);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("Adjacency list of vertex %d:\n", i);
        printf("head ");
        Node* current_node = graph->array[i].head;
        while (current_node != NULL) {
            printf("-> %d ", current_node->dest);
            current_node = current_node->next;
        }
        printf("\n\n");
    }
}

int main() {
    int V = 5;
    Graph* graph = newGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}
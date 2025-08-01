//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

// Node structure to represent a vertex in the graph
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Function to create a new node in a graph
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Allocate memory for adjacency list
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize adjacency list as empty
    for(int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge in a graph
void addEdge(struct Graph* graph, int src, int dest) {

    // Add an edge from source to destination
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for(int i = 0; i < graph->vertices; i++) {
        struct Node* node = graph->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while(node != NULL) {
            printf("%d -> ", node->vertex);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(MAX);

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
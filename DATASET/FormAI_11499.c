//FormAI DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in the graph
struct Node {
    int index;
    struct Node* next;
};

// Define a function to create a new node with a given index
struct Node* createNewNode(int i) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->index = i;
    newNode->next = NULL;
    return newNode;
}

// Define a struct to represent a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Define a function to create a new graph with a given number of vertices
struct Graph* createNewGraph(int numV) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numV;
    graph->adjLists = (struct Node**)malloc(sizeof(struct Node*) * numV);

    int i;
    for (i = 0; i < numV; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Define a function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex and add it to the source vertex's adjacency list
    struct Node* newNode = createNewNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Create a new node for the source vertex and add it to the destination vertex's adjacency list
    newNode = createNewNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Define a function to print a graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->index);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Create a new graph with 5 vertices
    struct Graph* graph = createNewGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    return 0;
}
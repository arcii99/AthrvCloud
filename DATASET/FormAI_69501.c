//FormAI DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>

#define MAX_VERTICES 100

// Structure for adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure for adjacent list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Structure for graph
typedef struct Graph {
    int vertices;
    AdjList* array;
} Graph;

// Function to create new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->array = (AdjList*) malloc(vertices * sizeof(AdjList));
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add edge to graph
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print graph
void printGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertices; i++) {
        AdjListNode* ptr = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n Head ", i);
        while (ptr) {
            printf("-> %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    int V = 6;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    printGraph(graph);
    return 0;
}
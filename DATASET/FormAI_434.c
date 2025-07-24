//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
/* I am a C program that represents a graph using an adjacency list. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} Head;

typedef struct {
    int vertices;
    Head* list;
} Graph;

/* Function to create a new node with a given vertex. */
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

/* Function to create a graph with n vertices. */
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->list = (Head*)malloc(vertices * sizeof(Head));
    
    for (int i = 0; i < vertices; i++) {
        graph->list[i].head = NULL;
    }
    
    return graph;
}

/* Function to add an edge to an undirected graph. */
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->list[src].head;
    graph->list[src].head = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->list[dest].head;
    graph->list[dest].head = newNode;
}

/* Function to print the graph. */
void printGraph(Graph* graph) {
    printf("Adjacency list of the graph:\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        Node* temp = graph->list[i].head;
        
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        
        printf("NULL\n");
    }
}

int main() {
    Graph* graph = createGraph(5);
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
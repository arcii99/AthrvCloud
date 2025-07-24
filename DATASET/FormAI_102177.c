//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Graph {
    int size;
    Node** vertices;
} Graph;

void addEdge(Graph* graph, int source, int destination) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = destination;
    node->next = graph->vertices[source];
    graph->vertices[source] = node;
}

void printGraph(Graph* graph) {
    for (int i=0; i<graph->size; i++) {
        printf("%d: ", i);
        Node* node = graph->vertices[i];
        while (node != NULL) {
            printf("%d ", node->value);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = 5;
    graph->vertices = (Node**)calloc(graph->size, sizeof(Node*));
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    printGraph(graph);
    return 0;
}
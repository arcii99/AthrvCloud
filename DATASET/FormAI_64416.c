//FormAI DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct graph {
    int vertices;
    Node** edges;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->edges = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->edges[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* node = malloc(sizeof(Node));
    node->val = dest;
    node->next = graph->edges[src];
    graph->edges[src] = node;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d => ", i);
        Node* node = graph->edges[i];
        while (node != NULL) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n");
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
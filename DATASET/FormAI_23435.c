//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertexCount;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertexCount) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjList = malloc(vertexCount * sizeof(Node*));

    int i;
    for (i = 0; i < vertexCount; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->vertexCount; i++) {
        Node* node = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (node) {
            printf("%d -> ", node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    return 0;
}
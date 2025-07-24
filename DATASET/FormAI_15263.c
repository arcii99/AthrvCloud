//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct graph {
    int vertexCount;
    Node** adjacencyList;
} Graph;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertexCount) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->adjacencyList = malloc(vertexCount * sizeof(Node*));
    int i;
    for (i = 0; i < vertexCount; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->vertexCount; v++) {
        Node* temp = graph->adjacencyList[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->value);
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
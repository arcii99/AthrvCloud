//FormAI DATASET v1.0 Category: Graph representation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct node {
    int val;
    struct node *next;
}Node;

typedef struct graph {
    int V; // number of vertices
    Node **adjList;
}Graph;

Node* createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjList = (Node**)malloc(V * sizeof(Node*));

    for(int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph *graph) {
    for(int i = 0; i < graph->V; i++) {
        Node *temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while(temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph *graph = createGraph(SIZE);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);

    printGraph(graph);

    return 0;
}
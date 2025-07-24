//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addEdge(struct Node* adjList[], int u, int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void printGraph(struct Node* adjList[], int v) {
    int i;
    struct Node* temp;
    for (i = 0; i < v; i++) {
        printf("Vertex %d: ", i);
        temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices = 5;
    struct Node* adjList[vertices];
    int i;
    for (i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);
    printGraph(adjList, vertices);
    return 0;
}
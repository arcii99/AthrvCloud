//FormAI DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *next;
};

void addEdge(struct Node *graph[], int u, int v) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void printGraph(struct Node *graph[], int V) {
    for(int i = 0; i < V; i++) {
        struct Node *curr = graph[i];
        printf("%d: ", i);
        while(curr != NULL) {
            printf("%d ", curr->val);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    struct Node *graph[V];
    for(int i = 0; i < V; i++) {
        graph[i] = NULL;
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph, V);
    return 0;
}
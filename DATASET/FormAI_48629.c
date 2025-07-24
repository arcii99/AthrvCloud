//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct node {
    int vertex;
    struct node* next;
} Node;

typedef struct graph {
    Node* vertices[MAX_VERTICES];
    int num_vertices;
} Graph;

void initGraph(Graph* g) {
    g->num_vertices = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->vertices[i] = NULL;
    }
}

void addVertex(Graph* g, int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    g->vertices[g->num_vertices] = newNode;
    g->num_vertices++;
}

void addEdge(Graph* g, int from, int to) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = to;
    newNode->next = g->vertices[from];
    g->vertices[from] = newNode;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        Node* ptr = g->vertices[i];
        printf("Vertex %d: ", i);
        while (ptr != NULL) {
            printf("%d -> ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph g;
    initGraph(&g);

    addVertex(&g, 0);
    addVertex(&g, 1);
    addVertex(&g, 2);
    addVertex(&g, 3);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 3);

    printGraph(&g);

    return 0;
}
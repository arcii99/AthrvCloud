//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define TRUE 1
#define FALSE 0

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct Graph {
    Node *vertices[MAX_SIZE];
    int visited[MAX_SIZE];
    int numVertices;
} Graph;

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = dest;
    newNode->next = graph->vertices[src];
    graph->vertices[src] = newNode;
}

void printGraph(Graph *graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        Node *curr = graph->vertices[i];
        printf("Vertex %d: ", i);
        while(curr != NULL) {
            printf("%d -> ", curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void dfs(Graph *graph, int start) {
    graph->visited[start] = TRUE;
    printf("%d ", start);
    Node *curr = graph->vertices[start];
    while(curr != NULL) {
        int vertex = curr->value;
        if(!graph->visited[vertex]) {
            dfs(graph, vertex);
        }
        curr = curr->next;
    }
}

int main() {
    Graph g;
    g.numVertices = 5;
    for(int i = 0; i < g.numVertices; i++) {
        g.vertices[i] = NULL;
        g.visited[i] = FALSE;
    }

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 4);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    printf("Adjacency List Representation:\n");
    printGraph(&g);

    printf("\nDepth First Search Traversal Order:\n");
    dfs(&g, 0);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
};

struct Node* addEdge(struct Node* root, int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = root;

    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdgeToGraph(struct Graph* graph, int src, int dest) {
    graph->adjList[src] = addEdge(graph->adjList[src], dest);
    graph->adjList[dest] = addEdge(graph->adjList[dest], src);
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("\nVertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdgeToGraph(graph, 0, 1);
    addEdgeToGraph(graph, 0, 4);
    addEdgeToGraph(graph, 1, 2);
    addEdgeToGraph(graph, 1, 3);
    addEdgeToGraph(graph, 1, 4);
    addEdgeToGraph(graph, 2, 3);
    addEdgeToGraph(graph, 3, 4);

    printGraph(graph);

    return 0;
}
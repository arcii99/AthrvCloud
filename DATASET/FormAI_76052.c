//FormAI DATASET v1.0 Category: Graph representation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

typedef struct Graph {
    int num_of_vertices;
    node** adj_list;
} Graph;

node* createNode(int vertex) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int num_of_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_of_vertices = num_of_vertices;
    graph->adj_list = malloc(num_of_vertices * sizeof(node*));
    for (int i = 0; i < num_of_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

void printGraph(Graph* graph) {
    printf("Graph representation using adjacency list:\n");
    for (int i = 0; i < graph->num_of_vertices; i++) {
        printf("Vertex %d: ", i);
        node* adj_list = graph->adj_list[i];
        while (adj_list != NULL) {
            printf("%d -> ", adj_list->vertex);
            adj_list = adj_list->next;
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
//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//The adjacency list node
typedef struct node {
    int vertex;
    struct node* next;
} Node;

//The Graph structure
typedef struct graph {
    int vertices;
    Node** list;
} Graph;

//A utility function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

//A utility function to create a new graph of n vertices
Graph* createGraph(int n) {
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = n;
    graph->list = malloc(n * sizeof(Node*));
    int i;
    for (i = 0; i < n; i++) {
        graph->list[i] = NULL;
    }
    return graph;
}

//A utility function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    //Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->list[src];
    graph->list[src] = newNode;

    //Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->list[dest];
    graph->list[dest] = newNode;
}

//A utility function to print the Graph
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->vertices; i++) {
        Node* temp = graph->list[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
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
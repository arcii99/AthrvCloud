//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

typedef struct graph {
    int V; //number of vertices
    Node** adjList; //adjacency list of the graph
}Graph;

//function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

//function to create a graph of V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(sizeof(Node*)*V);
    for(int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

//function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    //add edge from source to destination
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    //add edge from destination to source
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

//function to print the graph
void printGraph(Graph* graph) {
    for(int i = 0; i < graph->V; i++) {
        Node* curr = graph->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while(curr) {
            printf("%d -> ", curr->data);
            curr = curr->next;
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
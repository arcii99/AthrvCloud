//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

//define the node structure
struct Node {
    int vertex;
    struct Node* next;
};

//define the graph structure
struct Graph {
    int numOfVertices;
    struct Node** adjacencyList;
};

//create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

//create the graph
struct Graph* createGraph(int numOfVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numOfVertices = numOfVertices;
    graph->adjacencyList = malloc(sizeof(struct Node*) * numOfVertices);

    int i;
    for(i = 0; i < numOfVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

//add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

//print the graph
void printGraph(struct Graph* graph) {
    int i;
    for(i = 0; i < graph->numOfVertices; i++) {
        struct Node* temp = graph->adjacencyList[i];
        printf("\n Vertex %d: ", i);
        while(temp) {
            printf("%d ->", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//main function
int main() {
    struct Graph* graph = createGraph(5);
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
//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
//Structure to represent a node in graph
struct GraphNode {
    int data;
    struct GraphNode *next;
};

//Structure to represent graph
struct Graph {
    int vertices;
    struct GraphNode **adjList;
};

//Function to create a new node
struct GraphNode* createNode(int data) {
    struct GraphNode *newNode = malloc(sizeof(struct GraphNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = malloc(vertices * sizeof(struct GraphNode*));
    for(int i=0; i<vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

//Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    //Adding edge from src to dest
    struct GraphNode *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    //Adding edge from dest to src since graph is undirected
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

//Function to print the graph
void printGraph(struct Graph *graph) {
    printf("\nGraph Representation:\n");
    for(int i=0; i<graph->vertices; i++) {
        printf("Vertex %d -> ", i);
        struct GraphNode *temp = graph->adjList[i];
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = createGraph(5);

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
//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include<stdio.h> 

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

struct Graph 
{ 
    int n; 
    struct Node** adjList; 
}; 

struct Node* createNode(int data) 
{ 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 

struct Graph* createGraph(int n) 
{ 
    struct Graph* newGraph = malloc(sizeof(struct Graph)); 
    newGraph->n = n; 
    newGraph->adjList = malloc(n * sizeof(struct Node*)); 
    for (int i = 0; i < n; i++) 
        newGraph->adjList[i] = NULL; 
    return newGraph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjList[src]; 
    graph->adjList[src] = newNode; 

    newNode = createNode(src); 
    newNode->next = graph->adjList[dest]; 
    graph->adjList[dest] = newNode; 
} 

void printGraph(struct Graph* graph) 
{ 
    for (int i = 0; i < graph->n; i++) 
    { 
        printf("Vertex %d: ", i); 
        struct Node* node = graph->adjList[i]; 
        while (node != NULL) 
        { 
            printf("%d -> ", node->data); 
            node = node->next; 
        } 
        printf("NULL\n"); 
    } 
} 

int main() 
{ 
    int n = 5; 
    struct Graph* graph = createGraph(n); 
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
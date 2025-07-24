//FormAI DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
    int vertex; 
    struct Node* next; 
}; 

struct Graph 
{ 
    int numVertices; 
    struct Node** adjLists; 
}; 

struct Node* createNode(int v) 
{ 
    struct Node* newNode = malloc(sizeof(struct Node)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
}; 

struct Graph* createGraph(int vertices) 
{ 
    struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->numVertices = vertices; 

    graph->adjLists = malloc(vertices * sizeof(struct Node*)); 

    int i; 
    for (i = 0; i < vertices; i++) 
        graph->adjLists[i] = NULL; 

    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) 
{ 
    struct Node* newNode = createNode(dest); 
    newNode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newNode; 

    newNode = createNode(src); 
    newNode->next = graph->adjLists[dest]; 
    graph->adjLists[dest] = newNode; 
} 

void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->numVertices; v++) 
    { 
        struct Node* temp = graph->adjLists[v]; 
        printf("\n Adjacency list of vertex %d\n ", v); 
        while (temp) 
        { 
            printf("%d -> ", temp->vertex); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
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
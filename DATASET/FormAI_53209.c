//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>

int main() {
    printf("I'm so excited to show you my amazing C program for graph representation!\n");
    
    // First, let's define the number of vertices in our graph
    int numVertices = 5;
    printf("Our graph has %d vertices!\n", numVertices);
    
    // Now let's create a 2D matrix to represent the edges between vertices
    int edges[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    
    printf("The edges in our graph are represented by this matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
    
    printf("Isn't this amazing?? But wait, it gets even better!\n");
    
    // Now let's represent the graph using an adjacency list
    struct Node {
        int vertex;
        struct Node* next;
    };
    
    struct List {
        struct Node* head;
    };
    
    struct Graph {
        int numVertices;
        struct List* adjLists;
    };
    
    struct Graph* createGraph(int numVertices) {
        struct Graph* graph = malloc(sizeof(struct Graph));
        graph->numVertices = numVertices;
        
        graph->adjLists = malloc(numVertices * sizeof(struct List));
        for (int i = 0; i < numVertices; i++) {
            graph->adjLists[i].head = NULL;
        }
        
        return graph;
    }
    
    struct Node* createNode(int vertex) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->vertex = vertex;
        newNode->next = NULL;
        
        return newNode;
    }
    
    void addEdge(struct Graph* graph, int src, int dest) {
        struct Node* newNode = createNode(dest);
        newNode->next = graph->adjLists[src].head;
        graph->adjLists[src].head = newNode;
        
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest].head;
        graph->adjLists[dest].head = newNode;
    }
    
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    
    printf("And there you have it! Our graph in all its glory, represented using both a matrix and an adjacency list. Mind blown!\n");
    
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// data structure to represent an adjacency list node
struct AdjListNode {
int dest;
struct AdjListNode* next;
};

// data structure to represent an adjacency list
struct AdjList {
struct AdjListNode *head;
};

// data structure to represent a graph with adjacency lists
struct Graph {
int V;
struct AdjList* array;
};

// function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
struct AdjListNode* newNode =
    (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
newNode->dest = dest;
newNode->next = NULL;
return newNode;
}

// function to create a graph with V vertices
struct Graph* createGraph(int V) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
graph->V = V;

// create an array of adjacency lists
graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

// initialize each adjacency list as empty by making head as NULL
int i;
for (i = 0; i < V; ++i)
    graph->array[i].head = NULL;

return graph;
}

// function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
// add an edge from src to dest
struct AdjListNode* newNode = newAdjListNode(dest);
newNode->next = graph->array[src].head;
graph->array[src].head = newNode;

// add an edge from dest to src
newNode = newAdjListNode(src);
newNode->next = graph->array[dest].head;
graph->array[dest].head = newNode;
}

// function to print the graph
void printGraph(struct Graph* graph) {
int v;
for (v = 0; v < graph->V; ++v) {
    struct AdjListNode* pCrawl = graph->array[v].head;
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (pCrawl) {
        printf("-> %d", pCrawl->dest);
        pCrawl = pCrawl->next;
    }
    printf("\n");
}
}

int main() {
int V = 5;
struct Graph* graph = createGraph(V);
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
//FormAI DATASET v1.0 Category: Graph representation ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

struct graphNode {
    int dest;
    struct graphNode *next;
};

struct graph {
    int vertices;
    struct graphNode **adjlist;
};

// Create a new node
struct graphNode* createNode(int v) {
    struct graphNode* newNode = (struct graphNode*) malloc(sizeof(struct graphNode));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct graph* createGraph(int v) {
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->vertices = v;

    // Allocate memory for adjacency list
    g->adjlist = (struct graphNode**) malloc(sizeof(struct graphNode*) * v);

    // Initialize each adjacency list to NULL
    int i;
    for(i=0; i<v; i++) {
        g->adjlist[i] = NULL;
    }

    return g;
}

// Add edge
void addEdge(struct graph* g, int src, int dest) {
    // Add edge from src to dest
    struct graphNode* newNode = createNode(dest);
    newNode->next = g->adjlist[src];
    g->adjlist[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = g->adjlist[dest];
    g->adjlist[dest] = newNode;
}

// Print the graph
void printGraph(struct graph* g) {
    int i;
    for(i=0; i<g->vertices; i++) {
        struct graphNode* temp = g->adjlist[i];
        printf("Vertex %d:\n", i);
        while(temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program
int main() {
    // Create graph
    struct graph* g = createGraph(5);

    // Add edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    // Print the graph
    printGraph(g);

    return 0;
}
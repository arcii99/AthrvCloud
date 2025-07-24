//FormAI DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// structure for adjacency matrix representation of a graph
typedef struct graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// initialize the graph with 0 for all edges
void initGraph(Graph *g) {
    g->vertices = 0;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// add a vertex to the graph
void addVertex(Graph *g) {
    if (g->vertices < MAX_VERTICES) {
        g->vertices++;
    }
    else {
        printf("Cannot add vertex: maximum number of vertices reached!\n");
    }
}

// add an edge to the graph
void addEdge(Graph *g, int src, int dest) {
    if (src >= 0 && dest >= 0 && src < g->vertices && dest < g->vertices) {
        g->adjMatrix[src][dest] = 1;
        g->adjMatrix[dest][src] = 1;
    }
    else {
        printf("Cannot add edge: invalid vertex index!\n");
    }
}

// print the adjacency matrix representation of the graph
void printGraph(Graph *g) {
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// recursive DFS function to traverse the graph
void DFS(Graph *g, int v, int visited[]) {
    // mark vertex as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // recursively visit all unvisited neighbors of vertex v
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// DFS traversal of the graph starting from vertex v
void traverseDFS(Graph *g, int v) {
    int visited[g->vertices];

    // initialize all vertices as unvisited
    for (int i = 0; i < g->vertices; i++) {
        visited[i] = 0;
    }

    // start DFS traversal from vertex v
    DFS(g, v, visited);
}

int main() {
    Graph g;
    initGraph(&g);

    addVertex(&g);
    addVertex(&g);
    addVertex(&g);
    
    addEdge(&g, 0, 1);
    addEdge(&g, 1, 2);
    addEdge(&g, 2, 0);
    
    printGraph(&g);
    
    printf("DFS traversal starting from vertex 0:\n");
    traverseDFS(&g, 0);

    return 0;
}
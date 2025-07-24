//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>
#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // Undirected graph
}

void depthFirstSearch(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] && !visited[i]) {
            depthFirstSearch(i);
        }
    }
}

int main() {
    initializeGraph();
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 6);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 9);
    printf("Depth first search traversal: ");
    depthFirstSearch(0);
    printf("\n");
    return 0;
}
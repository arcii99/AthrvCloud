//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void initializeGraph(int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void printGraph(int n) {
    int i, j;
    printf("Graph:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void DFS(int v, int n) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++) {
        if(graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

int main() {
    int n = 6;
    int startingVertex = 0;
    initializeGraph(n);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);

    printf("DFS traversal starting from vertex %d: ", startingVertex);
    DFS(startingVertex, n);
    printf("\n");

    printGraph(n);

    return 0;
}
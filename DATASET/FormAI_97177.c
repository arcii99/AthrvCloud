//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#define MAX_VERTICES 10

int visited[MAX_VERTICES];

/* Recursive function to depth first search through graph */
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex) {
    printf("%d ", vertex); // print current vertex
    visited[vertex] = 1; // mark as visited
    for(int i = 0; i < MAX_VERTICES; i++) {
        if(graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(graph, i); // recursively search adjacent vertices
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = { {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                              {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                                              {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                                              {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
                                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                              {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
                                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                              {0, 0, 0, 0, 0, 1, 1, 1, 0, 0} };
    for(int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0; // mark all vertices as not visited
    }
    printf("Depth First Search traversal of graph:\n");
    DFS(graph, 0);
    printf("\n");
    return 0;
}
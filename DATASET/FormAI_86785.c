//FormAI DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>

#define MAX_VERTICES 50

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int vertex, int numVertices) {
    int i;

    visited[vertex] = 1;
    printf("%d ", vertex);

    for (i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] != 0 && !visited[i]) {
            dfs(i, numVertices);
        }
    }
}

int main() {
    int numVertices, i, j;

    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("The Depth First Search traversal of the graph is: ");
    for (i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    dfs(0, numVertices);

    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
#include <stdio.h>

#define MAX_VERTICES 100

int verticesCount = 0;
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

void addVertex() {
    if (verticesCount < MAX_VERTICES) {
        verticesCount++;
    }
}

void addEdge(int start, int end) {
    if (start < verticesCount && end < verticesCount) {
        adjacencyMatrix[start][end] = 1;
        adjacencyMatrix[end][start] = 1;
    }
}

void printGraph() {
    printf("Graph:\n");
    for (int i = 0; i < verticesCount; i++) {
        for (int j = 0; j < verticesCount; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    addVertex();
    addVertex();
    addVertex();
    addVertex();
    addVertex();

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    printGraph();
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>

#define MAX_VERTICES 10

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int degree[MAX_VERTICES];

void initializeGraph() {
    int i, j;

    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adjMatrix[i][j] = 0;
        }
        degree[i] = 0;
    }
}

void addEdge(int i, int j) {
    adjMatrix[i][j] = 1;
    adjMatrix[j][i] = 1;
    degree[i]++;
    degree[j]++;
}

void printGraph() {
    int i, j;

    printf("Adjacency Matrix:\n");
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Vertex Degrees:\n");
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("Vertex %d: %d\n", i, degree[i]);
    }
}

int main() {
    initializeGraph();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(3, 5);

    printGraph();

    return 0;
}
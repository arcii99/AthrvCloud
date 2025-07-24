//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#define N 5

void printGraph(int graph[][N], int size) {
    printf("\n Graph: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    printGraph(graph, N);
    return 0;
}
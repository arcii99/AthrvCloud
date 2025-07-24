//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include <stdio.h>

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int graph[vertices][vertices];

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the format of row, column:\n");

    for (int i = 0; i < edges; i++) {
        int row, column;
        scanf("%d %d", &row, &column);
        graph[row][column] = 1;
        graph[column][row] = 1;
    }

    printf("Here is the graph representation:\n");

    printf("  ");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
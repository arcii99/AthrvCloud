//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>

int main() {
    int rows, columns;
    printf("Please enter the dimensions of your graph:\n");
    printf("Number of rows: ");
    scanf("%d", &rows);
    printf("Number of columns: ");
    scanf("%d", &columns);
    
    // Create empty graph
    int graph[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;

    // Print graph
    printf("Graph representation:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
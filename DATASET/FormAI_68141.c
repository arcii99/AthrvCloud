//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Create the adjacency matrix
    int graph[rows][cols];

    // Initialize all values as 0
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            graph[i][j] = 0;
        }
    }

    // Set values in the adjacency matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(i == j) {
                // Set diagonal elements to 1
                graph[i][j] = 1;
            } else if(i < j) {
                // Randomly set non-diagonal elements to 0 or 1
                graph[i][j] = rand() % 2;
            } else {
                // Copy over value from the lower triangle
                graph[i][j] = graph[j][i];
            }
        }
    }

    // Print the adjacency matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
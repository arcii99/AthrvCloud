//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// function to print the adjacency matrix
void printAdjacencyMatrix(int matrix[][6], int n) {
    int i, j;

    printf("The adjacency matrix is:\n");

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main() {
    int n = 5, i, j;
    int matrix[6][6] = {0}; // initialize all elements to 0

    // add the edges to the graph
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[1][4] = 1;
    matrix[4][1] = 1;
    matrix[2][3] = 1;
    matrix[3][2] = 1;
    matrix[4][5] = 1;
    matrix[5][4] = 1;
    matrix[3][5] = 1;
    matrix[5][3] = 1;

    printAdjacencyMatrix(matrix, n); // print the adjacency matrix
    
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>

#define MAX_VERTICES 10

int adjacent_matrix[MAX_VERTICES][MAX_VERTICES];

int main() {

    printf("This program represents a directed graph using an adjacency matrix\n");

    // initialise the matrix with 0's
    for(int i=0; i<MAX_VERTICES; i++) {
        for(int j=0; j<MAX_VERTICES; j++) {
            adjacent_matrix[i][j] = 0;
        }
    }

    // add edges to the graph
    adjacent_matrix[0][1] = 1;
    adjacent_matrix[0][2] = 1;
    adjacent_matrix[1][3] = 1;
    adjacent_matrix[1][4] = 1;
    adjacent_matrix[2][4] = 1;
    adjacent_matrix[3][0] = 1;
    adjacent_matrix[4][3] = 1;
    adjacent_matrix[4][5] = 1;
    adjacent_matrix[5][5] = 1;

    // print the graph
    printf("\nThe adjacency matrix of the graph is:\n\n");
    for(int i=0; i<MAX_VERTICES; i++) {
        for(int j=0; j<MAX_VERTICES; j++) {
            printf("%d ", adjacent_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
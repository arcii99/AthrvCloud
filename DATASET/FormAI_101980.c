//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
// Welcome to my happy C Graph representation example program!

#include <stdio.h>

int main() {
    printf("Let's create a graph representation!\n");

    // First, let's define our graph with an array of edges
    int edges[6][2] = { {1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5} };

    // Now, let's create an adjacency matrix to represent the graph
    int adj_matrix[5][5] = {0}; // initialize to all 0's for now

    // Iterate through the edges and mark the corresponding matrix elements as 1's
    for (int i=0; i<6; i++) {
        int v1 = edges[i][0] - 1; // subtract 1 because vertices are numbered starting from 1
        int v2 = edges[i][1] - 1;
        adj_matrix[v1][v2] = 1;
        adj_matrix[v2][v1] = 1; // since this is an undirected graph, we also mark the reverse edge
    }

    // Finally, let's print out the adjacency matrix
    printf("\n");
    printf("Our graph representation is:\n");
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nHooray, we did it! Our graph is now represented by an adjacency matrix!\n");

    return 0;
}
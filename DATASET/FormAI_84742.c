//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include<stdio.h>

int main() {
    // A joyful day to you, dear user! Here is a C program that demonstrates graph representation using Adjacency Matrix.

    int no_of_vertices, no_of_edges, i, j;
    printf("Greetings, dear user! Please, enter the number of vertices and edges in your graph:\n");
    scanf("%d%d", &no_of_vertices, &no_of_edges);

    // Let's create an integer array to store our graph
    int graph[no_of_vertices][no_of_vertices];

    // Now, we will initialize our graph with zeroes, since we have not added any edges yet.
    for(i=0; i<no_of_vertices; i++) {
        for(j=0; j<no_of_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("\nGreat! Now, let's start adding the edges one by one.\n");
    printf("Please enter the vertices that form the edge:\n");

    // Taking input of the edges
    for(i=0; i<no_of_edges; i++) {
        int start_vertex, end_vertex;
        printf("\nEdge %d:\n", i+1);
        scanf("%d%d", &start_vertex, &end_vertex);

        // Adding the edge in the adjacency matrix
        graph[start_vertex][end_vertex] = 1;
        graph[end_vertex][start_vertex] = 1;
    }

    // Printing the adjacency matrix
    printf("\nGreat job! Here is the adjacency matrix representation of your graph:\n\n  ");

    // Printing the column numbers
    for(i=0; i<no_of_vertices; i++) {
        printf(" %d", i);
    }

    printf("\n  ");
    for(i=0; i<no_of_vertices; i++) {
        printf("__");
    }

    printf("\n");

    // Printing the matrix
    for(i=0; i<no_of_vertices; i++) {
        printf("%d|", i);

        for(j=0; j<no_of_vertices; j++) {
            printf(" %d", graph[i][j]);
        }

        printf("\n");
    }

    // Hooray, we are done!
    printf("\nWonderful! Thank you for using this program. Have a great day ahead!");

    return 0;
}
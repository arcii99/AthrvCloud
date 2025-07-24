//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
// This is going to be the most exciting C Graph representation example program you have ever seen!
#include<stdio.h>

int main() {
    int vertices, edges;
    printf("Welcome to the world of Graphs!\n");
    printf("How many vertices does your graph have? ");
    scanf("%d", &vertices);
    printf("And how many edges? ");
    scanf("%d", &edges);

    // Let's create the graph!
    int graph[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Now let's add some edges
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        printf("Enter the two vertices of edge %d: ", i+1);
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    // Finally, let's print the adjacency matrix
    printf("\nYour graph, represented by its adjacency matrix, is:\n\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\nIsn't this exciting? You just created a graph in C!\n");

    return 0;
}
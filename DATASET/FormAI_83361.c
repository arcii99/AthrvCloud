//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 50

int adj_list[MAX_VERTICES][MAX_VERTICES];
int n_vertices;

int main() {
    printf("Welcome to the curious world of graph representation!\n");
    printf("Please enter the number of vertices in your graph: ");
    scanf("%d", &n_vertices);

    printf("Great! Now let's build the adjacency list.\n");

    // Filling out the adjacency matrix 
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (i == j) {
                adj_list[i][j] = 0;
            } else {
                int decision;
                printf("Is vertex %d adjacent to vertex %d? (1 for Yes, 0 for No): ", i, j);
                scanf("%d", &decision);
                adj_list[i][j] = decision;
            }
        }
    }

    printf("\n");

    // Printing out the adjacency matrix
    printf("Adjacency List:\n");

    for (int i = 0; i < n_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < n_vertices; j++) {
            if (adj_list[i][j] == 1) {
                printf("%d ", j);
            }
        }
    }

    return 0;
}
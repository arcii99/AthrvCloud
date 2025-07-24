//FormAI DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>

#define MAX_LENGTH 10

int main() {
    int graph[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Input the graph data
    printf("Enter the graph data:\n");
    for(i=0; i<MAX_LENGTH; i++) {
        for(j=0; j<MAX_LENGTH; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the graph data using X and O for connections
    printf("Graph Representation using X and O:\n");
    for(i=0; i<MAX_LENGTH; i++) {
        for(j=0; j<MAX_LENGTH; j++) {
            if(graph[i][j]) {
                printf("X ");
            }
            else {
                printf("O ");
            }
        }
        printf("\n");
    }

    return 0;
}
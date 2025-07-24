//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>

int main() {
    printf("Hello there! Welcome to the happy graph representation program.\n");
    printf("Let's create a unique graph together!\n");

    int numVertices;
    printf("How many vertices would you like in your graph? ");
    scanf("%d", &numVertices);

    int adjacencyMatrix[numVertices][numVertices];
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    
    for(int i = 0; i < numVertices; i++) {
        for(int j = i+1; j < numVertices; j++) {
            int choice;
            printf("Is there an edge between vertex %d and %d? (0 for no, 1 for yes) ", i+1, j+1);
            scanf("%d", &choice);
            if(choice == 1) {
                adjacencyMatrix[i][j] = 1;
                adjacencyMatrix[j][i] = 1;
            }
        }
    }

    printf("Your graph, represented as an adjacency matrix, is:\n");
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Yay! We created a happy graph together. Let's create another one soon!\n");

    return 0;
}
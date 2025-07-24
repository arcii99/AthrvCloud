//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// A unique C Graph Representation example program
int main() {
    printf("Wow! I'm so excited to present to you my Graph Representation program!\n");
    printf("This program allows you to create a graph and represent it using adjacency matrix.\n");
    
    int vertices;
    printf("Enter the number of vertices in your graph: ");
    scanf("%d", &vertices);
    
    int **adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for(int i = 0; i < vertices; i++) {
        adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }
    
    printf("Great! Now, let's populate the adjacency matrix.\n");
    printf("Enter 1 if there is an edge between two vertices, 0 otherwise.\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("Is there an edge between Vertex %d and Vertex %d? ", i+1, j+1);
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    
    printf("Awesome work! Here's your adjacency matrix:\n");
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Thank you for using my program! Have a great day!\n");
    return 0;
}
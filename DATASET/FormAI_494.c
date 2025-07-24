//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include<stdio.h>
int main(){
    printf("Welcome to the happy graph representation program!\n\n");
    int n, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Great! Now enter the adjacency matrix for the graph:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nHere's your graph:\n\n");
    for(i=0; i<n; i++){
        printf("Vertex %d: ", i);
        for(j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\nWoohoo! Your graph has been represented successfully in the happy way!\n");
    return 0;
}
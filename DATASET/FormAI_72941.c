//FormAI DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int vertices, edges;
    int adjacent[MAX][MAX];
  
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
  
    // Initialize all elements of the adjacency matrix to 0
    for(int i = 0; i < vertices; ++i)
    {
        for(int j = 0; j < vertices; ++j)
        {
            adjacent[i][j] = 0;
        }
    }
  	
    // Filling the adjacency matrix
    printf("Enter the edges in (u v) format:\n");
    for(int i = 0; i < edges; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
      
        adjacent[u][v] = 1;
        adjacent[v][u] = 1;
    }
  	
    // Displaying the adjacency matrix
    printf("\nThe adjacency matrix for the given graph is:\n");
    for(int i = 0; i < vertices; ++i)
    {
        for(int j = 0; j < vertices; ++j)
        {
            printf("%d ", adjacent[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}
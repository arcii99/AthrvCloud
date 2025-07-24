//FormAI DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include<stdio.h>

int main(){
    int vertices, edges, i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    int graph[vertices][vertices];
    
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++)
            graph[i][j] = 0; //initialize all elements of adjacency matrix to 0
    }
    
    printf("\nEnter the edges (vertex 1 to vertex 2):\n");
    int vertex1, vertex2;
    for(i=0; i<edges; i++){
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1-1][vertex2-1] = 1;
        graph[vertex2-1][vertex1-1] = 1; //for undirected graph
    }
    
    printf("\nThe adjacency matrix is:\n");
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
// Romeo and Juliet's Undying Love Program

#include <stdio.h>
#include <stdlib.h>

int main() {
    int vertices, edges, vertex1, vertex2, i, j;
    
    // Taking input from user
    printf("Romeo and Juliet's Undying Love Graph\n\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    int graph[vertices][vertices];
    
    // Initializing all values of the graph to zero
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++){
            graph[i][j]=0;
        }
    }
    
    printf("Enter the vertices that make up each edge: \n");
    
    // Taking input for edges and assigning corresponding values in graph
    for(i=0; i<edges; i++){
        scanf("%d%d", &vertex1, &vertex2);
        graph[vertex1][vertex2]=1;
        graph[vertex2][vertex1]=1;
    }
    
    // Printing the graph
    printf("\nThe Graph is: \n");
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRomeo and Juliet are deeply in love!\n");
    
    return 0;
}
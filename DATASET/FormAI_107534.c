//FormAI DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include<stdio.h>

int main() {
    int vertices, edgeCount = 0, startVertex, endVertex;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    int graph[vertices][vertices];
    
    //initializing the graph with 0
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            graph[i][j] = 0;
        }
    }
    
    //get the edges of the graph from the user
    while(1) {
        printf("Enter edge %d (startVertex endVertex) or -1 to terminate: ", edgeCount+1);
        scanf("%d %d", &startVertex, &endVertex);
        
        if(startVertex == -1 || endVertex == -1) {
            //user has finished entering the edges
            break;
        }
        
        if(startVertex < 0 || startVertex >= vertices || endVertex < 0 || endVertex >= vertices) {
            printf("Invalid vertex. Please enter vertices between 0 and %d.\n", vertices-1);
        } else {
            graph[startVertex][endVertex] = 1;
            edgeCount++;
        }
    }
    
    //print the graph in matrix representation
    printf("\nGraph in matrix representation:\n");
    printf("    ");
    for(int i=0; i<vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i=0; i<vertices; i++) {
        printf("%d   ", i);
        for(int j=0; j<vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    //print the graph in list representation
    printf("\nGraph in list representation:\n");
    for(int i=0; i<vertices; i++) {
        printf("%d: ", i);
        for(int j=0; j<vertices; j++) {
            if(graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h> 

int main() 
{ 
    int numNodes, numEdges, i, j; 
    int G[10][10]; 
  
    printf("Enter the number of nodes in the network: "); 
    scanf("%d", &numNodes); 
  
    printf("Enter the number of edges in the network: "); 
    scanf("%d", &numEdges); 
  
    for(i = 1; i <= numNodes; i++) 
    { 
        for(j = 1; j <= numNodes; j++) 
        { 
            G[i][j] = 0; 
        } 
    } 
  
    printf("\nEnter the nodes connected by each edge:\n"); 

    for(i = 1; i <= numEdges; i++) 
    { 
        int node1, node2; 
        scanf("%d%d", &node1, &node2); 
  
        G[node1][node2] = 1; 
        G[node2][node1] = 1; 
    } 
  
    printf("\nThe network topology matrix is:\n"); 
    for(i = 1; i <= numNodes; i++) 
    { 
        for(j = 1; j <= numNodes; j++) 
        { 
            printf("%d ", G[i][j]); 
        } 
        printf("\n"); 
    } 
  
    return 0; 
}
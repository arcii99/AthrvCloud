//FormAI DATASET v1.0 Category: Graph representation ; Style: standalone
#include<stdio.h>

int n, i, j;

int main(){
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    
    int graph[n][n];
    
    printf("\nEnter the adjacency matrix: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    
    printf("\nThe given adjacency matrix is: \n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    
    printf("\nThe graph representation using adjacency list is: \n");
    for(i=0; i<n; i++){
        printf("Node %d : ",i+1);
        for(j=0; j<n; j++){
            if(graph[i][j] == 1){
                printf("%d -> ",j+1);
            }
        }
        printf("null\n");
    }
    
    return 0;
}
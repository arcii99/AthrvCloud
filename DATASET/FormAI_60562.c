//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main(){

    int nodes;
    printf("Enter number of nodes in the graph: \n");
    scanf("%d",&nodes);

    int graph[nodes][nodes];
    printf("Enter adjacency matrix for the graph: \n");
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            scanf("%d",&graph[i][j]);
        }
    }

    printf("\nGraph representation using adjacency matrix: \n");
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph representation using adjacency list:\n");
    for(int i=0; i<nodes; i++){
        printf("%d: ", i+1);
        for(int j=0; j<nodes; j++){
            if(graph[i][j]==1){
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }

    return 0;
}
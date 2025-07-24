//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main(){
    int graph[MAX][MAX],n,i,j;
    printf("Enter the number of vertices (N): ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix (N x N):\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nGraph Representation in C:\n\n");
    printf("   ");
    for(i=0;i<n;i++){
        printf("%d ",i+1);
    }
    printf("\n   ");
    for(i=0;i<n;i++){
        printf("__");
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d |",i+1);
        for(j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }   
    return 0;
}
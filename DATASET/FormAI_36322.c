//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
#include<stdio.h>

#define MAX_VERTICES 100

int n;
int G[MAX_VERTICES][MAX_VERTICES];

int main(){

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int i,j;

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }

    printf("\nAdjacency matrix:\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }

    printf("\nC graph representation:\n");

    printf("graph {\n");

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(G[i][j]){
                printf("%c--%c;\n",i+'A',j+'A');
            }
        }
    }

    printf("}\n");

    return 0;
}
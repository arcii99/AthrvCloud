//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include<stdio.h>

int main(){
    // Initializing the edge matrix with 0 initially
    int edges[10][10] = {0}; 

    int n, e;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);

    printf("Enter the number of edges : ");
    scanf("%d",&e);

    // Taking input of graph edges from user
    for(int i=0; i<e; i++){
        int u, v;
        printf("Enter edge %d (u v) : ",i+1);
        scanf("%d %d",&u,&v);
        edges[u][v] = 1; // Marking the edge between vertices u and v as 1
        edges[v][u] = 1; // Since it is undirected graph, marking the edge between v and u as 1
    }
    
    // Printing the graph using '+' and '-' symbols
    printf("Graph representation : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(edges[i][j] == 1){
                printf(" + ");
            }
            else{
                printf(" - ");
            }
        }
        printf("\n");
    }
    return 0;
}
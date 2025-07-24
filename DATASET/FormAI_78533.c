//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n); //taking input for number of nodes
    
    int graph[n][n]; //declaring a n x n matrix for the graph 
    
    //initializing the matrix with 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    
    int choice = 1;
    
    //loop for adding edges
    while(choice){
        int start, end;
        printf("Enter start node: ");
        scanf("%d",&start); //taking input for start node
        printf("Enter end node: ");
        scanf("%d",&end); //taking input for end node
        
        //adding the edge to the graph
        graph[start][end] = 1;
        graph[end][start] = 1;
        
        printf("Do you want to add more edges? (1 for yes, 0 for no)");
        scanf("%d",&choice); //taking input for continuing the loop or not
    }
    
    //printing the graph
    printf("Graph Representation (Adjacency Matrix):\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
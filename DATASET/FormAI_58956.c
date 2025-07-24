//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include<stdio.h>
#include<stdlib.h>

//Function to print the Graph
void printGraph(int **graph, int nodes){
    int i,j;
    printf(" ");
    for(i=0; i<nodes; i++)
        printf(" %d",i+1);
    printf("\n");
    for(i=0; i<nodes; i++){
        printf("%d ",i+1);
        for(j=0; j<nodes; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i, j, nodes;
    printf("Enter the number of nodes: ");
    scanf("%d",&nodes);
    int **graph;
    graph = (int **)malloc(nodes * sizeof(int *));
    for(i=0; i<nodes; i++){
        graph[i] = (int *)malloc(nodes*sizeof(int));
    }
    //Randomly creating the graph
    for(i=0; i<nodes; i++){
        for(j=0; j<nodes; j++){
            graph[i][j] = rand()%2;
        }
    }
    printf("Graph:\n");
    printGraph(graph, nodes);
    return 0;
}
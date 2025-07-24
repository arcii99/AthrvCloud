//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//function to add edge between two vertices
void addEdge(int **graph, int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}

//function to create graph
void createGraph(int **graph, int V){     
    for(int i=0;i<V;i++){
        graph[i] = (int *)malloc(V*sizeof(int)); //allocate memory for rows
        for(int j=0;j<V;j++){
            graph[i][j] = 0; //initialize every element to 0
        }
    }
    addEdge(graph,0,1);  //add edges to graph
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
}

//function to print graph
void printGraph(int **graph, int V){
    printf("\nAdjacency matrix representation of graph:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

//driver function
int main(){
    int V = 5; //number of vertices
    int **graph = (int **)malloc(V*sizeof(int *)); //allocate memory for columns
    createGraph(graph,V); //create graph
    printGraph(graph,V); //print graph
    return 0;
}
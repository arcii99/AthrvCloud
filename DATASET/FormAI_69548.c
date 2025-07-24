//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct Graph{
int vertices;
int** adjacency_matrix;
};
typedef struct Graph graph;

graph* CreateGraph(int vertices){
        graph* G=(graph*)malloc(sizeof(graph));
        G->vertices=vertices;
        G->adjacency_matrix=(int**)malloc(sizeof(int*)*vertices);
        for(int i=0;i<vertices;i++){
                G->adjacency_matrix[i]=(int*)malloc(sizeof(int)*vertices);
                for(int j=0;j<vertices;j++){
                        G->adjacency_matrix[i][j]=0;
                }
        }
        return G;
}

void AddDirectedEdge(graph* G,int source,int destination,int weight){
        G->adjacency_matrix[source][destination]=weight;
}

void PrintGraph(graph* G){
        printf("The adjacency matrix representation of the graph is:\n");
        for(int i=0;i<G->vertices;i++){
                for(int j=0;j<G->vertices;j++){
                        printf("%d ",G->adjacency_matrix[i][j]);
                }
                printf("\n");
        }
}

int main(){
        //Create Graph
        graph* G=CreateGraph(5);
        //Add edges
        AddDirectedEdge(G,0,1,5);
        AddDirectedEdge(G,1,2,3);
        AddDirectedEdge(G,2,3,4);
        AddDirectedEdge(G,3,4,8);
        AddDirectedEdge(G,4,0,1);
        //Print Graph
        PrintGraph(G);
        return 0;
}
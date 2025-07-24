//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the maximum number of vertices, for this example let's keep it 10
#define MAX_VERTICES 10

//Function to add an edge to the adjacency matrix
void addEdge(int source, int dest, int adj_mat[][MAX_VERTICES]){
    adj_mat[source][dest] = 1;
    adj_mat[dest][source] = 1;
}

//Function to print the adjacency matrix
void printAdjMat(int adj_mat[][MAX_VERTICES], int V){
    printf("\nNetwork Topology Mapper:\n\n");
    printf("     ");
    for(int i=0; i<V; i++)
        printf("%4d ", i);
    printf("\n");
    printf("-----------------------------------------\n");
    for(int i=0; i<V; i++){
        printf("%4d|", i);
        for(int j=0; j<V; j++){
            printf("%4d ", adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
}

//Main function (driver method)
int main(){
    int V, E, source, dest;

    printf("Enter the number of vertices in the network topology: ");
    scanf("%d", &V);

    int adj_mat[V][MAX_VERTICES];
    memset(adj_mat, 0, sizeof(adj_mat)); //Setting all values to 0 initially

    printf("\nEnter the number of edges to be added: ");
    scanf("%d", &E);

    printf("\nEnter the connections (source and destination) between nodes:\n");
    for(int i=0; i<E; i++){
        printf("\nEdge %d\n", i+1);
        printf("Enter source vertex: ");
        scanf("%d", &source);
        printf("Enter destination vertex: ");
        scanf("%d", &dest);
        addEdge(source, dest, adj_mat); //Adding the edge to the adjacency matrix
    }
    printf("\n");

    printAdjMat(adj_mat, V); //Printing the adjacency matrix

    return 0;
}
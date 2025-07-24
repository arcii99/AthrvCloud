//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#define MAX 100 //maximum number of nodes

//function to initialize the adjacency matrix
void initialize(int adjacency_matrix[MAX][MAX], int nodes) {
    int i,j;
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
}
//function to add an edge to the graph
void add_edge(int adjacency_matrix[MAX][MAX], int source, int destination) {
    adjacency_matrix[source][destination] = 1;
}

int main() {
    int nodes,edges,i,j;
    printf("Enter the number of nodes and edges in the graph:\n");
    scanf("%d%d",&nodes,&edges);
    int adjacency_matrix[MAX][MAX];
    initialize(adjacency_matrix, nodes);
    printf("Enter the source and destination for %d edges separated by a space:\n", edges);
    for(i = 0; i < edges; i++) {
        int source,destination;
        scanf("%d%d",&source,&destination);
        add_edge(adjacency_matrix, source, destination);
    }
    printf("The adjacency matrix of the graph is:\n");
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            printf("%d ",adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
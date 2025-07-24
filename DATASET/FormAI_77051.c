//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 20

// Adjacency matrix to store the graph
int adj_matrix[MAX_VERTEX][MAX_VERTEX];
int n;

// Function to add edge in graph
void add_edge(int u, int v){
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

// Function to display the graph
void display_graph(){
    int i,j;
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main Function
int main(){
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj_matrix[i][j]);
        }
    }
    display_graph();
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

#define V 5   // number of vertices

// define a matrix for adjacency representation
int adj_mat[V][V];

// function to add edge to the graph
void add_edge(int start, int end){
    adj_mat[start][end] = 1;
    adj_mat[end][start] = 1;
}

// function to print the graph
void print_graph(){
    printf("Graph:\n");
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}

// main function
int main(){
    // initialize matrix with 0
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            adj_mat[i][j] = 0;
        }
    }
    
    // add edges
    add_edge(0, 1);
    add_edge(0, 4);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    add_edge(2, 3);
    add_edge(3, 4);
    
    // print the graph
    print_graph();
    
    return 0;
}
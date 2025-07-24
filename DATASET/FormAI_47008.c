//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
    //create a graph of size 5
    int n = 5;
    int graph[n][n];
    //fill the graph with 0s
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graph[i][j] = 0;
        }
    }
    //add edges to the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    //print the graph
    printf("Surprise! Here is your graph:\n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
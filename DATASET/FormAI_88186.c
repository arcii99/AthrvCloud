//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include<stdio.h>

int main(){
    //creating nodes for the graph
    int nodes = 5;
    int graph[nodes][nodes];
    //initializing graph value to 0
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            graph[i][j] = 0;
        }
    }
    //creating edges for the graph
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    //displaying the graph
    printf("\n");
    printf("    1 2 3 4 5\n");
    printf("-------------\n");
    for(int i = 0; i < nodes; i++){
        printf("%d | ", i+1);
        for(int j = 0; j < nodes; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
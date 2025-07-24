//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include<stdio.h>
#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(){
    int i,j;
    for(i=0;i<MAX_VERTICES;i++){
        for(j=0;j<MAX_VERTICES;j++){
            graph[i][j]=0;
        }
    }
}

void addEdge(int from, int to){
    graph[from][to] = 1;
    graph[to][from] = 1;
}

void displayGraph(){
    int i,j;
    printf("\nGraph:\n");
    for(i=0;i<MAX_VERTICES;i++){
        for(j=0;j<MAX_VERTICES;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    initializeGraph();
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(1,2);
    addEdge(1,4);
    addEdge(2,3);
    addEdge(4,5);
    addEdge(5,6);
    displayGraph();
    return 0;
}
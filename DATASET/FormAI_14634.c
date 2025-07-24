//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Graph {
    int vertices;
    int edges;
    int matrix[MAX][MAX];
};

void initializeGraph(struct Graph* graphPointer){
    printf("\nEnter the number of vertices in the Graph: ");
    scanf("%d",&(graphPointer->vertices));
    printf("\nEnter the number of edges in the Graph: ");
    scanf("%d",&(graphPointer->edges));

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            graphPointer->matrix[i][j] = 0;
        }
    }

    int source,dest;
    for(int i=0;i<graphPointer->edges;i++){
        printf("\nEnter the source vertex of edge %d: ",i+1);
        scanf("%d",&source);
        printf("\nEnter the destination vertex of edge %d: ",i+1);
        scanf("%d",&dest);

        graphPointer->matrix[source][dest] = 1;
        graphPointer->matrix[dest][source] = 1;
    }
}

void printGraph(struct Graph* graphPointer){
    printf("\nAdjacency matrix of the Graph: \n\n");
    for(int i=0;i<graphPointer->vertices;i++){
        for(int j=0;j<graphPointer->vertices;j++){
            printf("%d\t",graphPointer->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct Graph graph;

    initializeGraph(&graph);
    printGraph(&graph);
    
    printf("\n");
    return 0;
}
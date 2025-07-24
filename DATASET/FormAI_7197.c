//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int graph[MAX_SIZE][MAX_SIZE];
int vertices;

void createGraph() {
    printf("\nEnter the number of vertices:");
    scanf("%d", &vertices);
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<vertices;i++) {
        printf("\nEnter the row %d:", i+1);
        for(int j=0;j<vertices;j++)
            scanf("%d",&graph[i][j]);
    }
}

void displayGraph() {
    printf("\nThe adjacency matrix is:\n");
    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++)
            printf("%d ",graph[i][j]);
        printf("\n");
    }
}

int main() {
    printf("\n*** C Program to create a graph representation ***\n");
    createGraph();
    displayGraph();
    return 0;
}
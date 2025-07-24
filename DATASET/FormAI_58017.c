//FormAI DATASET v1.0 Category: Graph representation ; Style: invasive
#include<stdio.h>
#define MAX 10

void createGraph(int graph[MAX][MAX], int vertices);
void displayGraph(int graph[MAX][MAX], int vertices);

int main() {
    int graph[MAX][MAX], vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph(graph, vertices);
    displayGraph(graph, vertices);

    return 0;   
}

void createGraph(int graph[MAX][MAX], int vertices) {
    int i, j;

    printf("Enter graph data in 0/1:\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void displayGraph(int graph[MAX][MAX], int vertices) {
    int i, j;

    printf("Adjacency Matrix of the Graph:\n");

    for (i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
 }
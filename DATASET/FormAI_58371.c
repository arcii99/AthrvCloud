//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include<stdio.h>

//Function to create a graph representation using
//an adjacency matrix where the edges represent the distance
void createGraph(int graph[][10], int vertices) {
    int i, j;
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            printf("Enter distance between vertex %d and %d: ", i+1, j+1);
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0) {
                graph[i][j] = 999;    //Distance is assigned as infinity to represent no edge
            }
        }
    }
}

//Function to print the graph representation
void printGraph(int graph[][10], int vertices) {
    int i, j;
    printf("\nThe graph representation using adjacency matrix:\n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            if(graph[i][j] == 999) {
                printf("INF\t");
            }
            else {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}

//Main function
int main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    int graph[10][10];
    createGraph(graph, vertices);
    printGraph(graph, vertices);
    return 0;
}
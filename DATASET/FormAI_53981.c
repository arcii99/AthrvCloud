//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include<stdio.h>

#define MAX_VERTICES 10

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};

void addEdge(int source, int destination) {
    adjacency_matrix[source][destination] = 1;
    adjacency_matrix[destination][source] = 1;
}

void displayGraph(int vertices) {
    int i, j;
    printf("The Adjacency Matrix Representation of the Graph:\n");
    for(i=0; i<vertices; i++) {
        for(j=0; j<vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, i, source, destination;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    for(i=0; i<edges; i++) {
        printf("Enter the source vertex and destination vertex of edge %d: ", i+1);
        scanf("%d%d", &source, &destination);
        addEdge(source, destination);
    }
    displayGraph(vertices);
    return 0;
}
//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vertices, edges, source;
    printf("Please enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Please enter the number of edges: ");
    scanf("%d", &edges);
    int** matrix = (int**) malloc(vertices * sizeof(int*));
    for(int i=0; i<vertices; i++){
        matrix[i] = (int*) calloc(vertices, sizeof(int));
    }
    for(int i=0; i<edges; i++){
        int x, y;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &x, &y);
        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;
    }
    printf("Matrix representation of the network topology:\n");
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Please enter the source vertex to find its neighbors: ");
    scanf("%d", &source);
    printf("Neighbors of vertex %d:\n", source);
    for(int i=0; i<vertices; i++){
        if(matrix[source-1][i] == 1){
            printf("%d ", i+1);
        }
    }
    free(matrix);
    return 0;
}
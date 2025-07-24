//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#define MAX 100

int main(){
    int vertices, edges, i, j, x, y;
    int matrix[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    //initialize matrix
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++){
            matrix[i][j] = 0;
        }
    }

    printf("\nEnter the edges (x, y):\n");

    //reading edges
    for(i=0; i<edges; i++){
        scanf("%d%d", &x, &y);
        matrix[x][y] = 1;
        matrix[y][x] = 1; //uncomment for directed graph
    }

    //printing matrix
    printf("\nAdjacency Matrix:\n");
    for(i=0; i<vertices; i++){
        for(j=0; j<vertices; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
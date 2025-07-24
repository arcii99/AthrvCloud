//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include<stdio.h>
#define N 5 //number of nodes

int main()
{
    int graph[N][N] = { {0, 5, 0, 0, 10},
                        {0, 0, 0, 6, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 7, 0, 0},
                        {0, 0, 0, 4, 0} }; //sample graph representation

    printf("Graph Representation:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
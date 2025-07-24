//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    int adj_matrix[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
    printf("Enter edges between vertices: \n");
    for(int i=0; i<m; i++)
    {
        int u, v;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        adj_matrix[u-1][v-1] = 1;
        adj_matrix[v-1][u-1] = 1;
    }
    printf("Adjacency matrix:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
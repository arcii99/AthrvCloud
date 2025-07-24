//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include <stdio.h>
#define MAX_NODE 100 // maximum number of nodes in the graph
 
int main()
{
    int graph[MAX_NODE][MAX_NODE]; // 2D array to hold graph nodes and edges
    int n, m; // n: number of nodes, m: number of edges
    int i, j, u, v;
 
    // get number of nodes and edges from user
    printf("Enter number of nodes and edges: ");
    scanf("%d%d", &n, &m);
 
    // initialize graph with no edges
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            graph[i][j] = 0;
        }
    }
 
    // input edges and update graph
    for(i=0; i<m; i++)
    {
        printf("Enter edge %d in format (u, v): ", i+1);
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
 
    // print graph
    printf("\nGraph representation:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}
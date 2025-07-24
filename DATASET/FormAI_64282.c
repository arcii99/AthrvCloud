//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include<stdio.h>

// function to construct the adjacency matrix
void constructGraph(int vertices, int edges, int graph[][vertices+1])
{
    int u, v;
    for(int i=1; i<=edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

// function to display the adjacency matrix
void displayGraph(int vertices, int graph[][vertices+1])
{
    printf("Adjacency matrix representation of the graph:\n");
    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// main function
int main()
{
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    int graph[vertices+1][vertices+1];
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    constructGraph(vertices, edges, graph);
    displayGraph(vertices, graph);
    return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void createGraph(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int start, int end)
{
    graph[start][end] = 1;
    graph[end][start] = 1;
}

void printGraph(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        printf("%d: ", i);
        
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        
        printf("\n");
    }
}

void DFS(int v, int vertices)
{
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < vertices; i++)
    {
        if (graph[v][i]==1 && visited[i]==0)
        {
            DFS(i, vertices);
        }
    }
}

int main()
{
    int vertices = 6;
    createGraph(vertices);
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);
    
    printf("The adjacency list representation of the graph is:\n");
    printGraph(vertices);
    
    printf("\nDepth First Traversal starting from vertex 0:\n");
    DFS(0, vertices);
    
    return 0;
}
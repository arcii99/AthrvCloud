//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V];
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++)
    {
        int minDist = INT_MAX;
        int minIndex;
        for(int j = 0; j < V; j++)
        {
            if(!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                minIndex = j;
            }
        }
        visited[minIndex] = 1;
        for(int j = 0; j < V; j++)
        {
            if(graph[minIndex][j] && !visited[j] && dist[minIndex] != INT_MAX && dist[minIndex] + graph[minIndex][j] < dist[j])
            {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for(int i = 0; i < V; i++)
    {
        printf("%d\t %d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    dijkstra(graph, 0);

    return 0;
}
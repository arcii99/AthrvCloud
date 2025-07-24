//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], int sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

int printSolution(int dist[], int n, int parent[], int src)
{
    printf("Vertex   Distance  Path\n");
    for (int i = 0; i < V; i++)
    {
        if (i == src)
            continue;

        printf("%d          %d      %d ", i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src)
{
     int dist[V];
     int sptSet[V];
     int parent[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, parent[i] = -1;

     dist[src] = 0;

     for (int count = 0; count < V - 1; count++)
     {
       int u = minDistance(dist, sptSet);

       sptSet[u] = 1;

       for (int v = 0; v < V; v++)
       {
         if (graph[u][v] && sptSet[v] == 0 && dist[u] != INT_MAX
                                       && dist[u] + graph[u][v] < dist[v])
         {
            parent[v]  = u;
            dist[v] = dist[u] + graph[u][v];
         }
       }
     }

     printSolution(dist, V, parent, src);
}

int main()
{
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
                      {1, 0, 4, 2, 7, 0},
                      {4, 4, 0, 3, 5, 0},
                      {0, 2, 3, 0, 4, 6},
                      {0, 7, 5, 4, 0, 7},
                      {0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
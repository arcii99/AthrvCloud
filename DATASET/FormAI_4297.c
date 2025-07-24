//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int minDistance(int dist[], int visited[]);
int printPath(int parent[], int j);
void printSolution(int dist[], int parent[]);

void dijkstra(int graph[ROW][COL], int start)
{
    int dist[ROW];
    int visited[ROW];
    int parent[ROW];

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < ROW; i++)
    {
        parent[start] = -1;
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // distance from source to itself is 0
    dist[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < ROW - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet visited.
        int u = minDistance(dist, visited);

        // Mark the picked vertex as visited
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < ROW; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest path from source to target
    printSolution(dist, parent);
}

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < ROW; v++)
    {
        if (visited[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

int printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return 0;

    printPath(parent, parent[j]);

    printf("%d ", j);

    return 1;
}

void printSolution(int dist[], int parent[])
{
    int start = 0;
    printf("Vertex    Distance    Path\n");
    for (int i = 1; i < ROW; i++)
    {
        printf("%d -> %d \t %d \t\t", start, i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main()
{
    int graph[ROW][COL] = {{0, 3, 0, 0, 4},
                           {3, 0, 4, 0, 0},
                           {0, 4, 0, 1, 0},
                           {0, 0, 1, 0, 2},
                           {4, 0, 0, 2, 0}};

    dijkstra(graph, 0);

    return 0;
}
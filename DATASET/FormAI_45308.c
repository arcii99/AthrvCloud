//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5
#define INF 99999

int minDistance(int dist[], int visited[])
{
    int min = INF, min_index;

    for (int i = 0; i < ROW * COL; i++)
        if (!visited[i] && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

void printPath(int path[], int dest)
{
    if (path[dest] == -1)
        return;

    printPath(path, path[dest]);
    printf("%d ", dest);
}

void dijkstra(int graph[ROW][COL], int src, int dest)
{
    int dist[ROW * COL], visited[ROW * COL], path[ROW * COL];

    for (int i = 0; i < ROW * COL; i++)
        dist[i] = INF, visited[i] = 0, path[i] = -1;

    dist[src] = 0;

    for (int i = 0; i < ROW * COL - 1; i++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < ROW * COL; v++)
            if (!visited[v] && graph[u / COL][u % COL] && dist[u] != INF
                && dist[u] + graph[u / COL][u % COL] < dist[v]) {
                dist[v] = dist[u] + graph[u / COL][u % COL];
                path[v] = u;
            }
    }

    printf("Minimum distance from source to destination: %d\n", dist[dest]);
    printf("Path: %d ", src);
    printPath(path, dest);
}

int main(void)
{
    int graph[ROW][COL] = {
        {0, 1, 0, 0, 5},
        {1, 0, 2, 0, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 3, 0, 4},
        {5, 0, 0, 4, 0}
    };

    int src = 0, dest = 24;
    dijkstra(graph, src, dest);

    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: expert-level
#include <stdio.h>
#include <limits.h>

#define ROW 5
#define COL 5
#define TOTAL_NODES ROW*COL

int grid[ROW][COL] = {{1, 1, 1, 1, 1}, {0, 0, 1, 0, 1}, {1, 1, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
int visited[TOTAL_NODES] = {0};
int distance[TOTAL_NODES] = {INT_MAX};
int parent[TOTAL_NODES] = {-1};

int get_min_distance_node()
{
    int min_val = INT_MAX, min_node;
    for (int i = 0; i < TOTAL_NODES; i++)
    {
        if (!visited[i] && distance[i] < min_val)
        {
            min_val = distance[i];
            min_node = i;
        }
    }
    return min_node;
}

void dijkstra(int start)
{
    distance[start] = 0;

    for (int count = 0; count < TOTAL_NODES - 1; count++)
    {
        int current_node = get_min_distance_node();
        visited[current_node] = 1;

        for (int i = 0; i < TOTAL_NODES; i++)
        {
            if (grid[current_node / COL][current_node % COL] && !visited[i] && grid[i / COL][i % COL] && distance[current_node] + 1 < distance[i])
            {
                distance[i] = distance[current_node] + 1;
                parent[i] = current_node;
            }
        }
    }

    int end = (ROW - 1) * COL + (COL - 1);
    printf("Shortest path from (0,0) to (%d,%d): ", ROW - 1, COL - 1);
    if (visited[end])
    {
        int path[TOTAL_NODES], i = 0;
        int temp = end;
        while (temp != -1)
        {
            path[i++] = temp;
            temp = parent[temp];
        }
        for (int j = i - 1; j > 0; j--)
            printf("(%d,%d) -> ", path[j] / COL, path[j] % COL);

        printf("(%d,%d)", ROW - 1, COL - 1);
    }
    else
        printf("No path exists.");
}

int main()
{
    dijkstra(0);
    return 0;
}
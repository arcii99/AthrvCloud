//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

int graph[ROW][COL] = {
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
};

//The breadth first search function
void BFS(int source, int dest, int parent[], int distance[])
{
    int visited[ROW] = {0};
    int queue[ROW];
    int front = 0;
    int rear = 0;
    int i;

    distance[source] = 0;
    visited[source] = 1;
    queue[rear] = source;
    rear++;

    //The searching and visiting part of the BFS algorithm
    while (front < rear)
    {
        int current = queue[front];
        front++;

        for (i = 0; i < ROW; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                queue[rear] = i;
                rear++;
            }
        }
    }
}

//The printing function for final output
void printPath(int parent[], int dest)
{
    if (parent[dest] == -1)
    {
        printf("\nDestination is unreachable from the source\n");
        return;
    }
    int path[ROW];
    int len = 0;

    while (dest != -1)
    {
        path[len] = dest;
        len++;
        dest = parent[dest];
    }

    printf("\nThe shortest path is : ");

    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d ", path[i]);
    }

    printf("\n");
}

int main()
{
    int source = 0;
    int dest = 9;
    int parent[ROW];
    int distance[ROW];
    int i;

    //The initializing and setting function that sets all values to default
    for (i = 0; i < ROW; i++)
    {
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    //The BFS function that finds the shortest path
    BFS(source, dest, parent, distance);

    //The printing function that prints out the shortest path
    printPath(parent, dest);

    return 0;
}
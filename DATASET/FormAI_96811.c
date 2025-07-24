//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 5
#define COL 5

int shortest_path(int graph[ROW][COL], int start, int end)
{
    int dist[ROW];
    int visited[ROW];
    int min_dist, current_vertex, i, j;
    
    // Initialize distance array and visited array
    for (i = 0; i < ROW; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    
    // Distance to starting vertex is zero
    dist[start] = 0;
    
    // Loop through all vertices
    for (i = 0; i < ROW - 1; i++) 
    {
        // Find vertex with shortest distance that has not been visited
        min_dist = INT_MAX;
        for (j = 0; j < ROW; j++)
        {
            if (!visited[j] && dist[j] <= min_dist)
            {
                min_dist = dist[j];
                current_vertex = j;
            }
        }

        // Mark vertex as visited
        visited[current_vertex] = 1;

        // Update distances of adjacent vertices
        for (j = 0; j < ROW; j++)
        {
            if (graph[current_vertex][j] && !visited[j] && dist[current_vertex] != INT_MAX && dist[current_vertex]+ graph[current_vertex][j] < dist[j])
            {
                dist[j] = dist[current_vertex] + graph[current_vertex][j];
            }
        }
    }

    // Return distance to target vertex
    return dist[end];
}

int main()
{
    int graph[ROW][COL] = {{0, 7, 0, 2, 0},
                           {7, 0, 1, 3, 5},
                           {0, 1, 0, 4, 0},
                           {2, 3, 4, 0, 6},
                           {0, 5, 0, 6, 0}};
                           
    int start = 1;
    int end = 4;
    int result = shortest_path(graph, start, end);
    
    printf("The shortest path from vertex %d to vertex %d is %d\n", start, end, result);

    return 0;
}
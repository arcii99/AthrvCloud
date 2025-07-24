//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>

#define ROW 10
#define COL 10

void printPath(int path[], int length)
{
    printf("The shortest path: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int dijkstra(int graph[ROW][COL], int start, int end)
{
    int dist[ROW];
    int prev[ROW];
    int visited[ROW];
    int path[ROW];
    
    // Initialize dist, prev and visited arrays
    for (int i=0; i<ROW; i++) {
        dist[i] = 1000;
        prev[i] = -1;
        visited[i] = 0;
    }
    
    // Distance to starting node is 0
    dist[start] = 0;
    
    for (int count = 0; count < ROW-1; count++)
    {
        int u = -1;
        int min = 1000;
        
        // Choose the vertex with the minimum distance
        for (int i = 0; i < ROW; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        
        if (u == -1) {
            break; // No path found
        }
        
        visited[u] = 1;
        
        // Update the distance of adjacent vertices
        for (int v = 0; v < ROW; v++)
        {
            if (graph[u][v] && !visited[v])
            {
                int alt = dist[u] + graph[u][v];
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }
    
    // Construct the shortest path
    int length = 0;
    
    for (int i=end; prev[i]!=-1; i=prev[i])
    {
        path[length++] = i;
    }
    
    path[length++] = start;
    
    // Reverse the path array
    for (int i=0; i<length/2; i++)
    {
        int temp = path[i];
        path[i] = path[length-i-1];
        path[length-i-1] = temp;
    }
    
    printPath(path, length);
    
    return dist[end];
}

int main()
{
    int graph[ROW][COL] = {
        {0, 7, 9, 0, 0, 14, 0, 0, 0, 0},
        {7, 0, 10, 15, 0, 0, 0, 0, 0, 0},
        {9, 10, 0, 11, 0, 2, 0, 0, 0, 0},
        {0, 15, 11, 0, 6, 0, 0, 9, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 14, 0},
        {14, 0, 2, 0, 0, 0, 6, 0, 0, 10},
        {0, 0, 0, 0, 0, 6, 0, 11, 0, 9},
        {0, 0, 0, 9, 0, 0, 11, 0, 0, 0},
        {0, 0, 0, 0, 14, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 10, 9, 0, 0, 0}
    };
    
    int start = 0;
    int end = 9;
    
    int shortestDist = dijkstra(graph, start, end);
    
    printf("The shortest distance from node %d to node %d is %d.\n", start, end, shortestDist);
    
    return 0;
}
//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Defining the number of vertices in the graph
#define V 8

// function to find the minimum distance between two nodes not yet included in the shortest path tree
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// function to print the shortest path from source to destination
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
    
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}

// function to print the final solution
void printSolution(int dist[], int parent[], int src, int dest)
{
    printf("Shortest Distance from %d to %d is: %d\n", src, dest, dist[dest]);
    printf("Shortest Path is: ");
    printf("%d ", src);
    printPath(parent, dest);
}

// function that implements A* algorithm
void astar(int graph[V][V], int src, int dest)
{
    // The output array. dist[i] will hold the shortest distance from src to i
    int dist[V];
    
    // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    int sptSet[V];
    
    // parent array to store the shortest path tree
    int parent[V];
    
    // Initialize all distances as INFINITE and sptSet[] as false
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, parent[i] = -1;
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // A* Algorithm begins here 
    for(int count = 0; count < V-1; count++)
    {
        // pick the vertex with minimum distance not yet included in the shortest path tree
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = 1;
    
        // Update dist value of the adjacent vertices of the picked vertex.
        for(int v = 0; v < V; v++)
        {
            // Update dist[v] only if it's not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    // print the shortest path from src to dest
    printSolution(dist, parent, src, dest);
}

// main function
int main()
{
    int graph[V][V] = { {0, 3, 0, 0, 7, 0, 0, 0},
                        {3, 0, 6, 10, 0, 0, 0, 0},
                        {0, 6, 0, 1, 0, 0, 0, 0},
                        {0, 10, 1, 0, 9, 0, 0, 0},
                        {7, 0, 0, 9, 0, 8, 0, 3},
                        {0, 0, 0, 0, 8, 0, 2, 0},
                        {0, 0, 0, 0, 0, 2, 0, 6},
                        {0, 0, 0, 0, 3, 0, 6, 0} };
    
    astar(graph, 0, 7);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include<stdio.h>
#include<limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with minimum distance value, from the set of vertices
// not yet included in shortest path tree (SPT)
int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// Function to print the final shortest path from source to target vertex using parent array
void printPath(int parent[], int j)
{
    // If j is source vertex, then we are at the beginning 
    if (parent[j] == -1)
        return;
 
    printPath(parent, parent[j]);
 
    printf("%d ", j);
}
 
// Function to print the final distance values calculated using Dijkstra's algorithm
void printSolution(int dist[], int n, int parent[], int start, int end)
{
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", start, i, dist[i], start);
        printPath(parent, i);
    }
}

// Function to implement Dijkstra's shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int start, int end)
{
    int dist[V]; // Array to store distance values from source vertex
    int sptSet[V]; // Array to store set of vertices included in shortest path tree
    
    int parent[V]; // Array to store shortest path tree
 
    // Initialize all distances to INFINITE and sptSet[] as 0
    for (int i = 0; i < V; i++)
    {
        parent[start] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
 
    // Distance of source vertex from itself is always 0
    dist[start] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = 1;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if distance between u and v is smaller than current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
 
    // Print the calculated shortest distance and the path from source to target vertex
    printSolution(dist, V, parent, start, end);
}
 
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 1},
                       {4, 0, 2, 5, 0},
                       {0, 2, 0, 1, 0},
                       {0, 5, 1, 0, 3},
                       {1, 0, 0, 3, 0}};
    
    int start_vertex = 0; // Source vertex
    int end_vertex = 4; // Target vertex
 
    dijkstra(graph, start_vertex, end_vertex);
 
    return 0;
}
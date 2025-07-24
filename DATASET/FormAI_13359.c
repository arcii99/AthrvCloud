//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: careful
#include<stdio.h>
#include<limits.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
  {0, 4, 2, 0, 0},
  {4, 0, 1, 3, 0},
  {2, 1, 0, 4, 5},
  {0, 3, 4, 0, 1},
  {0, 0, 5, 1, 0}
};

// A utility function to find the vertex with
// minimum distance value, from the set of vertices
// not yet included in shortest path tree
int minDistance(int dist[], int sptSet[]) {
   int min = INT_MAX, min_index;

   for (int v = 0; v < ROW; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[]) {
   printf("Vertex \t\t Distance from Source\n");
   for (int i = 0; i < ROW; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int src) {
     int dist[ROW];

     // sptSet[i] will be true if vertex i is included in shortest
     // path tree or shortest distance from src to i is finalized
     int sptSet[ROW];

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < ROW; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < ROW-1; count++) {
       // Pick the minimum distance vertex from the set of vertices
       // not yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = 1;

       // Update dist value of the adjacent vertices of the
       // picked vertex.
       for (int v = 0; v < ROW; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist);
}

// driver program to test above function
int main()
{
    dijkstra(0);
    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
/* This program implements Dijkstra’s shortest path algorithm using an adjacency matrix representation of a weighted, directed graph */ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

int minDistance(int dist[], int visited[]) {
   int min = INT_MAX, min_index;
   
   for (int i = 0; i < V; i++) {
      if (visited[i] == 0 && dist[i] <= min) {
         min = dist[i];
         min_index = i;
      }
   }
   return min_index;
}

int printSolution(int dist[], int n) {
   printf("Vertex   Distance from Source\n");
   for (int i=0; i<V; i++) {
      printf("%d \t\t %d\n", i, dist[i]);
   }
}

void dijkstra(int graph[V][V], int src) {
   int dist[V]; // Distance from source to each vertex
   int visited[V]; // Visited[i] will be 1 if vertex i is included in shortest path tree or shortest distance from src to i is finalized. 
   
   for (int i = 0; i < V; i++) {
      dist[i] = INT_MAX; // Initialize all distances as INFINITE and visited[] as 0
      visited[i] = 0;
   }
   
   dist[src] = 0; // Distance from source vertex to itself is 0
   
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, visited); // Pick the minimum distance vertex from the set of vertices not yet processed
      visited[u] = 1; // Mark the picked vertex as processed
      for (int v = 0; v < V; v++) {
         if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v]; // Update dist value of the adjacent vertices of the picked vertex
         }
      }
   }
   printSolution(dist, V); // Print the constructed distance array
}

int main() {
   int graph[V][V] = {{0, 4, 0, 0, 0},
                      {4, 0, 8, 0, 0},
                      {0, 8, 0, 7, 0},
                      {0, 0, 7, 0, 9},
                      {0, 0, 0, 9, 0}};
   
   dijkstra(graph, 0); // Calculate and print shortest distances from vertex 0 to all other vertices in the graph
   
   return 0;
}
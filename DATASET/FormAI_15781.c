//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int sptSet[]) {
   int min = INT_MAX, min_index;
   
   for (int v = 0; v < V; v++) 
      if (sptSet[v] == 0 && dist[v] <= min) 
         min = dist[v], min_index = v;

   return min_index;
}
 
// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
   if (parent[j] == -1) 
      return;
   
   printPath(parent, parent[j]);
 
   printf("%d ", j);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(int graph[V][V], int src, int des) {
   int dist[V];
   int sptSet[V];
   int parent[V];
 
   for (int i = 0; i < V; i++) {
      parent[src] = -1;
      dist[i] = INT_MAX;
      sptSet[i] = 0;
   }
 
   dist[src] = 0;
 
   for (int count = 0; count < V - 1; count++) {
      int u = minDistance(dist, sptSet);
      sptSet[u] = 1;
 
      for (int v = 0; v < V; v++) 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
            dist[u] + graph[u][v] < dist[v]) {
            parent[v] = u;
            dist[v] = dist[u] + graph[u][v];
         }  
   }
 
   printf("Shortest path from %d to %d: ", src, des);
   printf("%d ", src);
   printPath(parent, des);
   printf("\nShortest distance between nodes: %d\n", dist[des]);
}

// Main function
int main() {
   int graph[V][V] = {
      { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
   };
 
   printf("Thank you for using our Dijkstra algorithm to find the shortest path!\n\n");
   dijkstra(graph, 0, 8);
 
   return 0;
}
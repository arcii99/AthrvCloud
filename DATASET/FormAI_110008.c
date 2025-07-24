//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include<stdio.h>
#include<limits.h>

// function to find the minimum distance vertex from the set of vertices not yet visited
int minDist(int dist[], int visited[], int V) {

   int min = INT_MAX, min_index;
   
   for (int i = 0; i < V; i++) {
      if (visited[i] == 0 && dist[i] <= min) {
         min = dist[i];
         min_index = i;
      }
   }
   
   return min_index;
}

void dijkstra(int graph[][5], int source, int V) {
   int dist[V];
   int visited[V];
   
   for (int i = 0; i < V; i++) {
      dist[i] = INT_MAX;
      visited[i] = 0;
   }
   
   dist[source] = 0;
   
   for (int i = 0; i < V - 1; i++) {
      
      int u = minDist(dist, visited, V);
      
      visited[u] = 1;
      
      for (int v = 0; v < V; v++) {
         if (visited[v] == 0 && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
         }
      }
   }
   
   printf("Vertex Distance from Source\n");
   
   for (int i = 0; i < V; i++) {
      printf("%d\t\t%d\n", i, dist[i]);
   }
}

int main() {
   int graph[5][5] = {{0, 4, 0, 0, 7},
                      {4, 0, 8, 5, 0},
                      {0, 8, 0, 9, 0},
                      {0, 5, 9, 0, 6},
                      {7, 0, 0, 6, 0}};
                        
   dijkstra(graph, 0, 5);

   return 0;
}
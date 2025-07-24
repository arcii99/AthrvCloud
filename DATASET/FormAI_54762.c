//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
	{ 0, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 1 },
	{ 1, 0, 0, 1, 0 },
	{ 0, 1, 1, 0, 1 },
	{ 0, 1, 0, 1, 0 }
};

int visited[COL] = { 0 };

int minDistance(int dist[], int n) {
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < n; v++) {
     if (visited[v] == 0 && dist[v] <= min) {
         min = dist[v];
         min_index = v;
      }
   }
   return min_index;
}

void dijkstra(int src) {
     int dist[COL];

     for (int i = 0; i < COL; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
     }

     dist[src] = 0;

     for (int count = 0; count < COL - 1; count++) {
         int u = minDistance(dist, COL);
         visited[u] = 1;

         for (int v = 0; v < COL; v++) {
             if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                 && dist[u] + graph[u][v] < dist[v])
                 dist[v] = dist[u] + graph[u][v];
         }
     }
     printf("Vertex   Distance from Source\n");
     for (int i = 0; i < ROW; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    dijkstra(0);
    return 0;
}
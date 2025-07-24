//FormAI DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>

int main() {
   // Let's create a graph of cities and their distances
   
   // The graph can be represented using an adjacency matrix
   int graph[5][5] = {
      {0, 10, 0, 20, 0},
      {10, 0, 30, 0, 40},
      {0, 30, 0, 50, 60},
      {20, 0, 50, 0, 70},
      {0, 40, 60, 70, 0}
   };
   
   // Let's display the graph
   printf("Here's the graph:\n\n");
   printf("   A  B  C  D  E\n");
   printf("   ------------\n");
   
   for(int i = 0; i < 5; i++) {
      printf("%c| ", 'A' + i);
      for(int j = 0; j < 5; j++) {
         printf("%d  ", graph[i][j]);
      }
      printf("\n");
   }
   
   // You can use this graph to calculate the shortest distance between two cities using Dijkstra's algorithm or to find the minimum spanning tree using Kruskal's algorithm.
   
   return 0;
}
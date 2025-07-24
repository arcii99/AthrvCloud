//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include <stdio.h>

int main() {
   int vertices, edges, i, j, vertex1, vertex2, graph[100][100];
   
   printf("Enter the number of vertices: ");
   scanf("%d", &vertices);
   
   printf("Enter the number of edges: ");
   scanf("%d", &edges);
   
   // Initializing the graph with 0s
   for(i = 0; i < vertices; i++) {
      for(j = 0; j < vertices; j++) {
         graph[i][j] = 0;
      }
   }
   
   // Reading the edges from user
   for(i = 0; i < edges; i++) {
      printf("\nEnter edge %d vertices (u, v): ", i+1);
      scanf("%d%d", &vertex1, &vertex2);
      
      // Adding edge to the graph
      graph[vertex1][vertex2] = 1;
      graph[vertex2][vertex1] = 1;
   }

   // Printing the graph representation
   printf("\nThe graph representation in C style:\n");

   printf("   ");
   for (i = 0; i < vertices; i++) {
      printf("%d ", i);
   }

   printf("\n");
   for(i = 0; i < vertices; i++) {
      printf("%d| ", i);
      
      for(j = 0; j < vertices; j++) {
         printf("%d ", graph[i][j]);
      }
      
      printf("\n");
   }

   return 0;
}
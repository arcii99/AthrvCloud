//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>

int main() {
   int vertices, edges, i, j, vertex1, vertex2;
   
   printf("Enter the number of vertices: ");
   scanf("%d", &vertices);
   
   int adjacency_matrix[vertices][vertices];
   
   for(i = 0; i < vertices; i++) {
      for(j = 0; j < vertices; j++) {
         adjacency_matrix[i][j] = 0; // initialize all values to 0
      }
   }
   
   printf("Enter the number of edges: ");
   scanf("%d", &edges);
   
   for(i = 0; i < edges; i++) {
      printf("Enter vertex 1 and vertex 2 of edge %d (separated by space): ", i+1);
      scanf("%d %d", &vertex1, &vertex2);
      
      // update the adjacency matrix to show the edge between vertex1 and vertex2
      adjacency_matrix[vertex1-1][vertex2-1] = 1;
      adjacency_matrix[vertex2-1][vertex1-1] = 1;
   }
   
   printf("\nAdjacency Matrix:\n");
   
   for(i = 0; i < vertices; i++) {
      for(j = 0; j < vertices; j++) {
         printf("%d ", adjacency_matrix[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}
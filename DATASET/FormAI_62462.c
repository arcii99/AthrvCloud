//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>

int main() {

   int n, i, j;

   printf("Enter number of nodes in the graph: ");
   scanf("%d", &n);

   int graph[n][n];

   printf("Enter adjacency matrix values of the graph:\n");
   for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
         scanf("%d", &graph[i][j]);
      }
   }

   printf("\nRepresentation of the graph is:\n");
   for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
         printf("%d ", graph[i][j]);
      }
      printf("\n");
   }

   return 0;
}
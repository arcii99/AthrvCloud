//FormAI DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>

int main()
{
   int vertices, edges, i, j, source, destination;

   printf("Enter the number of vertices: ");
   scanf("%d", &vertices);

   int graph[vertices][vertices];

   for (i = 0; i < vertices; i++) {
      for (j = 0; j < vertices; j++) {
         graph[i][j] = 0;
      }
   }

   printf("Enter the number of edges: ");
   scanf("%d", &edges);

   for (i = 0; i < edges; i++) {
      printf("Enter the source and destination of edge %d: ", i+1);
      scanf("%d%d", &source, &destination);
      graph[source][destination] = 1;
      graph[destination][source] = 1;
   }

   printf("Graph representation:\n");

   for (i = 0; i < vertices; i++) {
      printf("%d: ", i);
      for (j = 0; j < vertices; j++) {
         if (graph[i][j] == 1) {
            printf("%d ", j);
         }
      }
      printf("\n");
   }

   return 0;
}
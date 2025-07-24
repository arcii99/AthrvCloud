//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>

int main() {
   int vertices, i, j, edge_counter = 0;
   printf("Enter the number of vertices: ");
   scanf("%d", &vertices);
   
   int graph[vertices][vertices]; // Adjacency matrix
   
   // Initializing the graph
   for (i = 0; i < vertices; i++) {
      for (j = 0; j < vertices; j++) {
         graph[i][j] = 0; // No edges between vertices
      }
   }
   
   // Adding edges to the graph
   while (1) {
      int vertex1, vertex2;
      printf("Enter edge (-1 -1 to exit): ");
      scanf("%d %d", &vertex1, &vertex2);
      if (vertex1 == -1 && vertex2 == -1) {
         break; // Exit loop
      }
      graph[vertex1][vertex2] = 1; // Creating an edge between two vertices
      graph[vertex2][vertex1] = 1; // Graph is undirected
   }
   
   // Printing the graph
   printf("\nThe graph generated is:\n");
   for (i = 0; i < vertices; i++) {
      for (j = 0; j < vertices; j++) {
         printf("%d ", graph[i][j]);
         if (graph[i][j] == 1) {
            edge_counter++;
         }
      }
      printf("\n");
   }
   
   // Printing the number of edges in the graph
   printf("\nNumber of edges: %d\n", edge_counter/2); // Divide by 2 since graph is undirected
   
   return 0;
}
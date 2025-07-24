//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include <stdio.h>

int main() {
   int n, m;
   printf("Enter number of vertices: ");
   scanf("%d", &n);
   int graph[n][n];
   
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           graph[i][j] = 0;
       }
   }
   
   printf("Enter number of edges: ");
   scanf("%d", &m);
   
   for (int i = 0; i < m; i++) {
       int u, v;
       printf("Enter edge %d (u v): ", i+1);
       scanf("%d %d", &u, &v);
       
       // Add edge to graph
       graph[u-1][v-1] = 1;
       graph[v-1][u-1] = 1;
   }
   
   // Print adjacency matrix representation of graph   
   printf("\nAdjacency Matrix Representation:\n\n   ");
   for (int i = 1; i <= n; i++) {
       printf("%d ", i);
   }
   printf("\n");
   for (int i = 0; i < n; i++) {
       printf("%d  ", i+1);
       for (int j = 0; j < n; j++) {
           printf("%d ", graph[i][j]);
       }
       printf("\n");
   }
   
   return 0;
}
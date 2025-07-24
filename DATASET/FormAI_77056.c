//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main() {
   int V = 5;

   int** graph = (int**) malloc(V * sizeof(int*));
   for (int i = 0; i < V; i++) {
       graph[i] = (int*) malloc(V * sizeof(int));
   }

   graph[0][1] = 1;
   graph[0][2] = 1;
   graph[1][0] = 1;
   graph[1][2] = 1;
   graph[1][3] = 1;
   graph[2][0] = 1;
   graph[2][1] = 1;
   graph[2][3] = 1;
   graph[2][4] = 1;
   graph[3][1] = 1;
   graph[3][2] = 1;
   graph[3][4] = 1;
   graph[4][2] = 1;
   graph[4][3] = 1;

   printf("Graph representation in adjacency matrix form:\n");

   for (int i = 0; i < V; i++) {
       for (int j = 0; j < V; j++) {
           printf("%d ", graph[i][j]);
       }
       printf("\n");
   }

   return 0;
}
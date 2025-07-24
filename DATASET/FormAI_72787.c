//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
   // creating an array to store the edges of the graph
   int edges[10][10];
   int nodes, i, j;
   printf("Enter the number of nodes in the graph: ");
   scanf("%d", &nodes);

   // get the input for the edges of the graph
   printf("Enter the edges of the graph:\n");

   for (i = 0; i < nodes; i++){
      for (j = 0; j < nodes; j++){
         scanf("%d", &edges[i][j]);
      }
   }

   // print the adjacency matrix representation of the graph
   printf("Adjacency Matrix:\n");
   for (i = 0; i < nodes; i++){
      for (j = 0; j < nodes; j++){
         printf("%d ", edges[i][j]);
      }
      printf("\n");
   }

   // print the adjacency list representation of the graph
   printf("Adjacency List:\n");
   for (i = 0; i < nodes; i++){
      printf("%d: ", i+1);
      for (j = 0; j < nodes; j++){
         if (edges[i][j] == 1){
            printf("%d ", j+1);
         }
      }
      printf("\n");
   }

   return 0;
}
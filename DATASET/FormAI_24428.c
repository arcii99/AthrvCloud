//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

int max(int n, int m) {
   return n > m ? n : m;
}

int main() {

   int n, m, i, j, k, count = 0; 
   
   printf("Enter the no. of vertices: ");
   scanf("%d", &n);
   
   int graph[n][n];
   
   printf("Enter the adjacency matrix: \n");
   
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", &graph[i][j]);
       }
   }
   
   printf("Enter the no. of colors: ");
   scanf("%d", &m);
   
   int color[n];
   
   for (i = 0; i < n; i++) {
       color[i] = 0;
   }
   
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           if (graph[i][j] != 0 && color[j] == color[i]) {
               color[j] = (color[j] + 1)%m;
               count++;
           }
       }
   }
   
   printf("\nColors Assigned: \n");
   
   for (i = 0; i < n; i++) {
       printf("Vertex %d -> Color %d\n", i + 1, color[i] + 1);
   }
   
   printf("\nTotal no. of conflicts: %d\n", count);
   
   return 0;
}
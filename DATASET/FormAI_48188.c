//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
// Romeo, the pathfinder, is searching for the shortest route to reach Juliet.
#include<stdio.h>

int main() {
   int distance[4][4] = {{0, 5, 2, 6},
                         {5, 0, 4, 2},
                         {2, 4, 0, 3},
                         {6, 2, 3, 0}};
   int i, j, k, n=4;
   
   printf("Romeo: Oh, fair Juliet, I must reach thy tender side!\n");
   printf("Juliet: Oh, Romeo, my love, how can I make that come true?\n");
   printf("Romeo: Let me use my pathfinding skills to find the shortest path to reach thy side...\n");
   
   // Using Floyd-Warshall algorithm to find the shortest path
   for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
         for (j = 0; j < n; j++) {
            if (distance[i][k] + distance[k][j] < distance[i][j])
               distance[i][j] = distance[i][k] + distance[k][j];
         }
      }
   }
   
   printf("Romeo: Ah, my sweet Juliet, I have found the shortest path to reach thee!\n");
   printf("Juliet: Oh Romeo, speak, how may I reach you?\n");
   printf("Romeo: Nay, fair Juliet, I shall come to thee. The path I shall take is: ");
   
   // Printing the shortest path
   for(i=0; i<n; i++) {
      if(i!=0) printf(" -> ");
      printf("%d", i+1);
      if(i==n-1) printf(", the path ends at thy door.\n");
   }
   
   return 0;
}
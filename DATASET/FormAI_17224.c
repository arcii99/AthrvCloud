//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include<stdio.h>

int main(){
   int size, i, j;
   printf("Enter the size of the graph: ");
   scanf("%d", &size);
   int graph[size][size];
   
   // initializing the graph
   for(i=0; i<size; i++){
      for(j=0; j<size; j++){
          graph[i][j] = 0;
      }
   }
   
   // adding edges to the graph
   graph[0][1] = 1;
   graph[1][2] = 1;
   graph[2][3] = 1;
   graph[3][4] = 1;
   graph[4][0] = 1;
   graph[1][4] = 1;
   
   // displaying the graph
   printf("Graph:\n\n");
   for(i=0; i<size; i++){
      for(j=0; j<size; j++){
          printf("%d ", graph[i][j]);
      }
      printf("\n");
   }
   return 0;
}
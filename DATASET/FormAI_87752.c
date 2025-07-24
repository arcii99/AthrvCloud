//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include<stdio.h>

int main() {
   int i,j,n;
   printf("Enter the number of vertices in the graph: ");
   scanf("%d",&n);

   int graph[n][n];
   printf("Enter the adjacency matrix of the graph:\n");
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         scanf("%d",&graph[i][j]);
      }
   }
   
   int colors[n];
   for(i=0;i<n;i++){
      colors[i] = 0;
   }

   printf("\nThe vertices are colored as:\n");

   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         if(graph[i][j] && colors[i] == colors[j]){
            colors[j] = colors[i]+1;
         }
      }
   }
  
   for(i=0;i<n;i++){
      printf("Vertex %d: Color %d\n",i+1,colors[i]+1);
   }
   
   return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>

int main() {
   // declaring a 2D array to store the graph
   int graph[10][10];
   int nodes,edges,i,j;

   printf("Enter the number of nodes in the graph: ");
   scanf("%d",&nodes);

   //initialize the graph with all zeros
   for(i=0;i<nodes;i++) {
      for(j=0;j<nodes;j++) {
         graph[i][j]=0;
      }
   }

   printf("Enter the number of edges in the graph: ");
   scanf("%d",&edges);

   //read and add edges to the graph
   for(i=0;i<edges;i++) {
      int u,v;
      printf("\nEnter edge %d (u,v): ",i+1);
      scanf("%d %d",&u,&v);
      graph[u][v]=1;
      graph[v][u]=1; //uncomment this line for undirected graph
   }

   //printing the graph
   printf("\nThe adjacency matrix of the graph is:\n\n");
   for(i=0;i<nodes;i++) {
      for(j=0;j<nodes;j++) {
         printf("%d ",graph[i][j]);
      }
      printf("\n");
   }
   return 0;
}
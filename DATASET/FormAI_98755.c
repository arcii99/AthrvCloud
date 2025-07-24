//FormAI DATASET v1.0 Category: Graph representation ; Style: secure
#include<stdio.h>

int main()
{
   int numVertices, numEdges, i, j, startVertex, endVertex, edgeWeight;
   int graph[10][10];  // maximum number of vertices in the graph is 10
   //initialize the graph vertices to be unconnected
   for(i=0;i<10;i++){
      for(j=0;j<10;j++){
         graph[i][j] = 0;
      }
   }
   printf("Enter the number of vertices and edges in the graph (max 10):\n");
   scanf("%d%d", &numVertices, &numEdges);
   printf("Enter the details of each edge (start vertex, end vertex, weight):\n");
   //populate the graph with edge details
   for(i=0;i<numEdges;i++){
      scanf("%d%d%d", &startVertex, &endVertex, &edgeWeight);
      graph[startVertex][endVertex] = edgeWeight;
      graph[endVertex][startVertex] = edgeWeight; // since the graph is undirected
   }
   printf("\n\nThe graph is represented below:\n");
   //print the graph representation matrix
   for(i=0;i<numVertices;i++){
      for(j=0;j<numVertices;j++){
         printf("%d ", graph[i][j]);
      }
      printf("\n");
   }
   return 0;
}
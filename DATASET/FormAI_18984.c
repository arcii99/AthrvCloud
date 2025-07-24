//FormAI DATASET v1.0 Category: Graph representation ; Style: peaceful
#include<stdio.h>

int main(){

  int numVertices, numEdges, i, j, x, y;

  printf("Enter number of vertices in the graph:\n");
  scanf("%d",&numVertices);
  int graph[numVertices][numVertices];

  // initializing graph with no edges
  for(i=0;i<numVertices;i++){
    for(j=0;j<numVertices;j++){
      graph[i][j] = 0;
    }
  }

  printf("Enter number of edges in the graph:\n");
  scanf("%d",&numEdges);

  printf("Enter the pair of vertices for the edges:\n");
  for(i=0;i<numEdges;i++){
    scanf("%d %d",&x,&y);
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  printf("The graph in adjacency matrix format:\n");

  // printing the adjacency matrix
  for(i=0;i<numVertices;i++){
    for(j=0;j<numVertices;j++){
      printf("%d ",graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
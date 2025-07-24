//FormAI DATASET v1.0 Category: Graph representation ; Style: beginner-friendly
#include <stdio.h>

int main()
{
  int vertexCount, edgeCount, i, j, vertex1, vertex2;
  printf("Enter the number of vertices of the graph: ");
  scanf("%d",&vertexCount);
  printf("Enter the number of edges of the graph: ");
  scanf("%d",&edgeCount);
  int graph[vertexCount][vertexCount];
  for(i=0;i<vertexCount;++i)
    for(j=0;j<vertexCount;++j)
      graph[i][j]=0;
  for(i=0;i<edgeCount;++i)
  {
    printf("Enter the vertices of edge %d: ",i+1);
    scanf("%d%d",&vertex1,&vertex2);
    graph[vertex1-1][vertex2-1]=1;
    graph[vertex2-1][vertex1-1]=1;
  }
  printf("\nAdjacency Matrix:\n");
  for(i=0;i<vertexCount;++i)
  {
    for(j=0;j<vertexCount;++j)
      printf("%d ",graph[i][j]);
    printf("\n");
  }
  printf("\nGraph Representation:\n");
  for(i=0;i<vertexCount;++i)
  {
    printf("%d",i+1);
    for(j=0;j<vertexCount;++j)
    {
      if(graph[i][j]==1)
        printf(" -> %d",j+1);
    }
    printf("\n");
  }
  return 0;
}
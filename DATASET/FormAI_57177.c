//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include<stdio.h>

int main()
{
  int vertices, edges;
  printf("Enter the number of vertices:");
  scanf("%d", &vertices);
  printf("Enter the number of edges:");
  scanf("%d", &edges);

  int graph[vertices][edges];
  for(int i=0; i<vertices; i++)
  {
      for(int j=0; j<edges; j++)
      {
          graph[i][j] = 0;
      }
  }

  printf("\n------Graph Representation-------\n");

  for(int i=0; i<vertices; i++)
  {
      printf("Enter the connected vertices of %d:\n", i);
      for(int j=0; j<edges; j++)
      {
          scanf("%d", &graph[i][j]);
      }
  }

  printf("\n------Graph-------\n");
  for(int i=0; i<vertices; i++)
  {
      printf("|%d|", i);
      for(int j=0; j<edges; j++)
      {
          printf(" %d ", graph[i][j]);
      }
      printf("\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n, k, x, y;
  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);
  int** graph = (int**)malloc(n*sizeof(int*));
  for(int i=0; i<n; i++)
  {
    graph[i] = (int*)calloc(n, sizeof(int));
  }
  printf ("\nEnter the edge details in format 'start_vertex end_vertex'\n(Enter '-1 -1' to stop)\n");
  while (1)
  {
    scanf("%d%d",&x,&y);
    if(x==-1 || y==-1)
    {
      break;
    }
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  printf("\nThe graph adjacency matrix representation is:\n\n");
  printf("    ");
  for(int i=0; i<n; i++)
  {
    printf("%d   ",i);
  }
  printf("\n\n");
  for(int i=0; i<n; i++)
  {
    printf("%-3d", i);
    for(int j=0; j<n; j++)
    {
      printf("%-4d",graph[i][j]);
    }
    printf("\n\n");
  }
  return 0;
}
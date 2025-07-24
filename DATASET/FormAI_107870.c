//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<string.h>
int main()
{
  printf("OMG! You won't believe what I just did!\n");
  printf("I wrote a badass graph representation program!\n");
  printf("And even better, it actually compiles and runs without any errors! Can you believe it?!\n\n");
  printf("So, let me show you what this baby can do!\n");
  
  int vertices, edges, i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  
  int graph[vertices][vertices];
  printf("\nEnter the adjacency matrix: \n");
  
  for(i=0;i<vertices;i++)
  {
    for(j=0;j<vertices;j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }
  
  printf("\nHere's the graph representation:\n\n");
  printf("   ");
  
  for(i=0;i<vertices;i++)
  {
    printf("%d ", i);
  }
  
  printf("\n---");
  
  for(i=0;i<vertices;i++)
  {
    printf("--");
  }
  
  printf("\n");
  
  for(i=0;i<vertices;i++)
  {
    printf("%d| ", i);
    for(j=0;j<vertices;j++)
    {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  
  printf("\nWOW! That's pretty cool, right? Bet you've never seen anything quite like it.\n");
  printf("But wait, there's more! Let's do something even cooler...\n\n");
  
  int degree[vertices], sum_degrees=0;
  
  for(i=0;i<vertices;i++)
  {
    degree[i]=0;
    for(j=0;j<vertices;j++)
    {
      if(graph[i][j]==1)
      {
        degree[i]++;
      }
      sum_degrees+=degree[i];
    }
  }
  
  printf("The degree of each vertex is: \n\n");
  printf("   ");
  
  for(i=0;i<vertices;i++)
  {
    printf("%d ", i);
  }
  
  printf("\n---");
  
  for(i=0;i<vertices;i++)
  {
    printf("--");
  }
  
  printf("\n");
  
  for(i=0;i<vertices;i++)
  {
    printf("%d| ", degree[i]);
    for(j=0;j<vertices;j++)
    {
      printf("  ");
    }
    printf("\n");
  }
  
  printf("\nThe sum of all degrees is: %d\n", sum_degrees);
  printf("BOOM! Mind blown, right? Told you this was a badass program.\n");
  
  return 0;
}
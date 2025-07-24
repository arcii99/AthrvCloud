//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#define MAX 20

int main(){
  int n,i,j;
  int graph[MAX][MAX];
  printf("Enter the number of vertices: ");
  scanf("%i", &n);
  printf("Enter the graph:\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      scanf("%i", &graph[i][j]);
    }
  }
  printf("\nGraph Representation:\n");

  for(i=0;i<n;i++){
    printf("\n\t%c",i+65);
    for(j=0;j<n;j++){
      if(graph[i][j]==1)
          printf(" -> %c",j+65);
    }
    printf("\n");
  }
  printf("\n");

 return 0;
}
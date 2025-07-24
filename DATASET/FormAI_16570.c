//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

#define MAX 10

int main() {
  int i, j;
  int n;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);

  int adj[MAX][MAX];
  printf("Enter the adjacency matrix of the graph: \n");
  
  //Inputting the adjacency matrix
  for(i=0;i<n;i++) {
      for(j=0;j<n;j++) {
          scanf("%d", &adj[i][j]);
      }
  }

  printf("\nThe adjacency matrix representation of the graph is:\n");
  
  //Printing the adjacency matrix
  for(i=0;i<n;i++) {
      for(j=0;j<n;j++) {
          printf("%d ", adj[i][j]);
      }
      printf("\n");
  }

  return 0;
}
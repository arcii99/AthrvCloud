//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

int main() {
  int n, i, j;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);

  // declare the adjacency matrix 
  int adjMat[n][n];

  // initialize the adjacency matrix to 0
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      adjMat[i][j] = 0;
    }
  }
  
  // take the input for the adjacency matrix
  printf("Enter the adjacency matrix:\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      scanf("%d", &adjMat[i][j]);
    }
  }

  // print the adjacency matrix
  printf("The adjacency matrix is:\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      printf("%d ", adjMat[i][j]);
    }
    printf("\n");
  }

  return 0;
}
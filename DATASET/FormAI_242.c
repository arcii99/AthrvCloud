//FormAI DATASET v1.0 Category: Graph representation ; Style: scientific
#include <stdio.h>
#define N 5

int main()
{
  int i, j, adjMatrix[N][N];

  // Initialize adj matrix with zeros
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      adjMatrix[i][j] = 0;
    }
  }

  // Set edges in the graph
  adjMatrix[0][1] = 1;
  adjMatrix[1][0] = 1;
  adjMatrix[1][2] = 1;
  adjMatrix[2][1] = 1;
  adjMatrix[2][3] = 1;
  adjMatrix[3][2] = 1;
  adjMatrix[3][4] = 1;
  adjMatrix[4][3] = 1;
  
  // Print adjacency matrix
  printf("Graph represented by adjacency matrix:\n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>

int main() {
  int n, i, j, k;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);

  int G[n][n];

  printf("Enter the adjacency matrix:\n");

  // Take input for adjacency matrix
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      scanf("%d", &G[i][j]);
    }
  }

  printf("The graph is represented by the following adjacency matrix:\n");

  // Display the adjacency matrix
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }

  printf("The graph can be represented by the following vertex-edge list:\n");

  // Display the vertex-edge list
  for (i=0; i<n; i++) {
    printf("%d -> ", i+1);
    for (j=0; j<n; j++) {
      if (G[i][j] == 1) {
        printf("%d ", j+1);
      }
    }
    printf("\n");
  }

  return 0;
}
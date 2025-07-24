//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>

int main() {
  // Define number of vertices
  int n = 8;

  // Adjacency List representation
  int adj[8][8] = {
    {0, 1, 0, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
  };

  printf("Irregular C-Graph Representation\n\n");

  // Print adjacency list
  for (int i = 0; i < n; i++) {
    printf("%d: ", i);
    for (int j = 0; j < n; j++) {
      if (adj[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }

  return 0;
}
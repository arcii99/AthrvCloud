//FormAI DATASET v1.0 Category: Graph representation ; Style: future-proof
#include <stdio.h>

struct Graph {
   int v;
   int e;
} g;

int main() {
  printf("Enter number of vertices and edges: ");
  scanf("%d %d", &g.v, &g.e);

  int edge[g.e][2];

  printf("Enter edges (by their endpoints):\n");
  for(int i=0; i<g.e; i++) {
    scanf("%d %d", &edge[i][0], &edge[i][1]);
  }

  printf("\nGraph has %d vertices and %d edges.\n", g.v, g.e);
  printf("Edge list of graph:\n");
  for(int i=0; i<g.e; i++) {
    printf("%d - %d\n", edge[i][0], edge[i][1]);
  }

  int matrix[g.v][g.v];
  for(int i=0; i<g.v; i++) {
    for(int j=0; j<g.v; j++) {
      matrix[i][j] = 0;
    }
  }

  for(int i=0; i<g.e; i++) {
    matrix[edge[i][0]][edge[i][1]] = 1;
    matrix[edge[i][1]][edge[i][0]] = 1;
  }

  printf("\nAdjacency matrix of graph:\n");
  for(int i=0; i<g.v; i++) {
    for(int j=0; j<g.v; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
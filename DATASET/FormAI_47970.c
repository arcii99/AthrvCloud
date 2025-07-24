//FormAI DATASET v1.0 Category: Graph representation ; Style: visionary
#include <stdio.h>

int main() {
  int nodes, edges;
  printf("Enter the number of nodes: ");
  scanf("%d", &nodes);
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  int graph[nodes][nodes];

  int i, j;

  for(i = 0; i < nodes; i++) {
    for(j = 0; j < nodes; j++) {
      graph[i][j] = 0;
    }
  }

  printf("Enter the edges in the format i, j: ");
  for(i = 0; i < edges; i++) {
    int x, y;
    scanf("%d,%d", &x, &y);
    graph[x][y] = 1;
    graph[y][x] = 1;
  }

  printf("The adjacency matrix is:\n");
  for(i = 0; i < nodes; i++) {
    for(j = 0; j < nodes; j++) {
      printf("%3d", graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
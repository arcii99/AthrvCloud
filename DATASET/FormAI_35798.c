//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#define MAXV 100

int adj[MAXV][MAXV];

int main() {
  int n, m, i, j, v1, v2;

  // Read in number of vertices and edges
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges: ");
  scanf("%d", &m);

  // Initialize adjacency matrix to 0's
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      adj[i][j] = 0;
    }
  }

  // Read in edges and populate adjacency matrix
  for (i = 1; i <= m; ++i) {
    printf("Enter vertices of edge %d: ", i);
    scanf("%d %d", &v1, &v2);
    adj[v1][v2] = adj[v2][v1] = 1; // Undirected graph, so set both ways
  }

  // Print adjacency matrix
  printf("\nAdjacency matrix:\n");
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  return 0;
}
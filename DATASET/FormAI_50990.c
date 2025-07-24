//FormAI DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>

#define MAX_VERTICES 50

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void addEdge(int src, int dest) {
  adj_matrix[src][dest] = 1;
  adj_matrix[dest][src] = 1;
}

int main() {
  int n, m, i, j, src, dest;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges: ");
  scanf("%d", &m);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  printf("Enter the edges (source, destination):\n");
  for (i = 0; i < m; i++) {
    scanf("%d%d", &src, &dest);
    addEdge(src, dest);
  }

  printf("Adjacency Matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
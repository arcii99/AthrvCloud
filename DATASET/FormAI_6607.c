//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>

int main() {
  int n = 5;

  // Initialize graph
  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  // Add edges to graph
  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[1][3] = 1;
  graph[2][3] = 1;
  graph[3][4] = 1;

  // Print graph
  printf("Graph representation:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
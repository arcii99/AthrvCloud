//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>

int main() {
  int vertices, edges, i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  int graph[vertices][vertices];
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      graph[i][j] = 0;
    }
  }

  int e1, e2;
  for (i = 0; i < edges; i++) {
    printf("Enter edge %d: ", i + 1);
    scanf("%d%d", &e1, &e2);
    graph[e1][e2] = 1;
    graph[e2][e1] = 1;
  }

  printf("\nGraph:\n");
  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
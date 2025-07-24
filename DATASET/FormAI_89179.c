//FormAI DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>

int main(void) {
  int n, m;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  // Create an adjacency matrix
  int graph[n][n];

  // Initialize all elements to 0
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      graph[i][j] = 0;
    }
  }

  printf("Enter the number of edges: ");
  scanf("%d", &m);

  // Add edges to the graph
  printf("Enter the 'from' and 'to' nodes for each edge:\n");
  for(int i=0; i<m; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    graph[from][to] = 1;
  }

  // Print the graph
  printf("The graph in matrix representation:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
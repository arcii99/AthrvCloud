//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>

int main() {
  int nodes;
  printf("Enter the number of nodes: ");
  scanf("%d", &nodes);

  int adjMatrix[nodes][nodes]; // adjacency matrix to represent graph

  // initialize matrix with zeroes
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  // take input of edges
  int edges;
  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++) {
    int source, destination;
    printf("Enter edge %d: ", i+1);
    scanf("%d %d", &source, &destination);
    adjMatrix[source][destination] = 1;
    adjMatrix[destination][source] = 1; // undirected graph
  }

  // print the graph representation
  printf("Graph representation using adjacency matrix:\n");
  printf("  ");

  for (int i = 0; i < nodes; i++) {
    printf("%d ", i);
  }

  printf("\n");

  for (int i = 0; i < nodes; i++) {
    printf("%d ", i);
    for (int j = 0; j < nodes; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
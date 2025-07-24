//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

int main() {
  printf("Hey there, let's draw a graph!\n");

  int numNodes;
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &numNodes);

  int adjMatrix[numNodes][numNodes];

  printf("Enter the adjacency matrix (0 for no connection, 1 for connection):\n");
  for (int i=0; i<numNodes; i++) {
    for (int j=0; j<numNodes; j++) {
      scanf("%d", &adjMatrix[i][j]);
    }
  }

  printf("\nOur graph looks like this:\n\n");

  // Draw the graph
  for (int i=0; i<numNodes; i++) {
    for (int j=0; j<numNodes; j++) {
      if (adjMatrix[i][j] == 1) {
        printf("  %d --- %d\n", i, j);
      }
    }
  }

  printf("\nThank you for drawing our graph!\n");

  return 0;
}
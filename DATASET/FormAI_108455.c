//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

int main() {

  int numVertices;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &numVertices);

  int graph[numVertices][numVertices];

  // Initialize the graph matrix to 0
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      graph[i][j] = 0;
    }
  }

  // Ask user to enter the edges of the graph
  printf("\nEnter the edges of the graph in the format 'vertex1 vertex2':\n");
  printf("Enter -1 to stop.\n");

  int vertex1, vertex2;

  do {
    scanf("%d %d", &vertex1, &vertex2);
    if (vertex1 != -1 && vertex2 != -1) {
      graph[vertex1][vertex2] = 1;
      graph[vertex2][vertex1] = 1;
    }
  } while (vertex1 != -1 && vertex2 != -1);

  printf("\nGraph representation using adjacency matrix:\n");

  // Print the graph matrix
  for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  return 0;
}
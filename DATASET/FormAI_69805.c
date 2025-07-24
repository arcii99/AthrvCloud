//FormAI DATASET v1.0 Category: Graph representation ; Style: brave
#include <stdio.h>

int main() {
  printf("Welcome to the Graph Representation program!\n\n");

  /* Creating a 5x5 matrix to represent the graph */
  int graph[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
  };

  /* Printing the matrix to represent the graph */
  printf("Graph Representation:\n");
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  /* Printing the edges in the graph */
  printf("Edges in the Graph:\n");
  for(int i = 0; i < 5; i++) {
    for(int j = i+1; j < 5; j++) {
      if(graph[i][j] == 1) {
        printf("%d -> %d\n", i+1, j+1);
      }
    }
  }
  printf("\n");

  /* Printing the degree of each vertex in the graph */
  printf("Degree of each Vertex:\n");
  for(int i = 0; i < 5; i++) {
    int degree = 0;
    for(int j = 0; j < 5; j++) {
      if(graph[i][j] == 1) {
        degree++;
      }
    }
    printf("Vertex %d: %d\n", i+1, degree);
  }
  printf("\n");

  return 0;
}
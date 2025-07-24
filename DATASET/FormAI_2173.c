//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>

int main() {
  printf("\nWelcome to my C graph representation program!\n\n");

  // create a 2D array to represent the graph
  int graph[5][5] = {{0, 1, 0, 1, 0},
                     {1, 0, 1, 0, 1},
                     {0, 1, 0, 1, 0},
                     {1, 0, 1, 0, 1},
                     {0, 1, 0, 1, 0}};

  // print the graph representation
  printf("Here is the graph represented as an adjacency matrix:\n\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  // print the graph as a series of vertices and edges
  printf("\nHere is the graph represented as a series of vertices and edges:\n\n");
  for (int i = 0; i < 5; i++) {
    printf("Vertex %d: ", i+1);
    for (int j = 0; j < 5; j++) {
      if (graph[i][j] == 1) {
        printf("%d ", j+1);
      }
    }
    printf("\n");
  }

  printf("\nThanks for using my program! Have a great day :)\n");

  return 0;
}
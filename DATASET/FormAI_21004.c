//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **graph;
  int vertices = 6;

  // allocate memory for graph
  graph = (int **)malloc(vertices * sizeof(int *));
  for(int i=0; i<vertices; i++) {
    graph[i] = (int *)malloc(vertices * sizeof(int));
  }

  // initialize graph
  for(int i=0; i<vertices; i++) {
    for(int j=0; j<vertices; j++) {
      if(i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = rand() % 10;
      }
    }
  }

  // print graph
  printf(" Graph Representation in C (Adjacency Matrix)\n");
  printf("  --------------------------------------------\n");
  for(int i=0; i<vertices; i++) {
    printf("  | ");
    for(int j=0; j<vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("|\n");
  }
  printf("  --------------------------------------------\n");

  // deallocate memory
  for(int i=0; i<vertices; i++) {
    free(graph[i]);
  }
  free(graph);

  return 0;
}
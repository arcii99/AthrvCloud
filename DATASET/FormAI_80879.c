//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>

int main() {
  int edges = 6;
  int vertices = 5;
  int adjacency_matrix[vertices][vertices];
  int i, j;

  //Initializing the adjacency matrix
  for(i = 0; i < vertices; i++){
    for(j = 0; j < vertices; j++){
      adjacency_matrix[i][j] = 0;
    }
  }

  //Adding edges to the graph
  adjacency_matrix[0][1] = 1;
  adjacency_matrix[0][2] = 1;
  adjacency_matrix[1][0] = 1;
  adjacency_matrix[1][2] = 1;
  adjacency_matrix[1][3] = 1;
  adjacency_matrix[2][0] = 1;
  adjacency_matrix[2][1] = 1;
  adjacency_matrix[2][3] = 1;
  adjacency_matrix[3][1] = 1;
  adjacency_matrix[3][2] = 1;
  adjacency_matrix[3][4] = 1;
  adjacency_matrix[4][3] = 1;

  //Printing the adjacency matrix
  printf("Adjacency Matrix:\n\n");
  for(i = 0; i < vertices; i++){
    for(j = 0; j < vertices; j++){
      printf("%d ", adjacency_matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
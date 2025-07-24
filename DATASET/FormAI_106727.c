//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10

/* 
   This is a simple program to create the graph representation of a connected, directed, weighted graph
   with ten vertices. The program creates random edge weights between 1 and 50 for each edge, and outputs
   the adjacency matrix representation of the graph.
*/

int main() {
  int vertices[MAX_VERTICES][MAX_VERTICES];
  int i, j;
  
  /* Seed random number generator with current time */
  srand(time(NULL));
  
  /* Fill in the upper diagonal of the adjacency matrix with random edge weights */
  for(i=0; i<MAX_VERTICES; i++) {
    for(j=i+1; j<MAX_VERTICES; j++) {
      vertices[i][j] = rand() % 50 + 1; 
    }
  }
  
  /* Fill in the lower diagonal with zeros */
  for(i=0; i<MAX_VERTICES; i++) {
    for(j=0; j<i; j++) {
      vertices[i][j] = 0;
    }
  }
  
  /* Output the adjacency matrix as a table */
  printf("The adjacency matrix for the graph is:\n");
  for(i=0; i<MAX_VERTICES; i++) {
    for(j=0; j<MAX_VERTICES; j++) {
      printf("%3d ", vertices[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
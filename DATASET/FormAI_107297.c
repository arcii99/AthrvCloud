//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Touring
#include <stdio.h>

int main() {
  int nodes = 5;
  int edges = 7;
  int graph[nodes][nodes];
  int i,j;
  //initialize the graph with random binary values
  for(i=0; i<nodes; i++) {
    for(j=0; j<nodes; j++) {
      graph[i][j] = rand() % 2;
    }
  }
  //print out the adjacency matrix
  printf("The adjacency matrix for this network topology is:\n");
  for(i=0; i<nodes; i++) {
    for(j=0; j<nodes; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  //check for cycles and print the result
  int cycle = 0;
  for(i=0; i<nodes-1; i++) {
    for(j=i+1; j<nodes; j++) {
      if(graph[i][j] && graph[j][i]) {
        cycle = 1;
        break;
      }
    }
    if(cycle) break;
  }
  if(cycle) {
    printf("This network topology contains a cycle.\n");
  } else {
    printf("This network topology does not contain a cycle.\n");
  }
  return 0;
}
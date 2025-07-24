//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>

#define MAX 10

int adjMatrix[MAX][MAX];
int numNodes;

void createGraph() {
  printf("Enter number of nodes: ");
  scanf("%d", &numNodes);
  printf("Enter adjacency matrix:\n");
  for(int i=0; i<numNodes; i++) {
    for(int j=0; j<numNodes; j++) {
      scanf("%d", &adjMatrix[i][j]);
    }
  }
}

void displayGraph() {
  printf("\nAdjacency Matrix:\n");
  for(int i=0; i<numNodes; i++) {
    for(int j=0; j<numNodes; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  createGraph();
  displayGraph();
  
  return 0;
}
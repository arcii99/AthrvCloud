//FormAI DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>

void main() {
  printf("The world as we knew it is gone.\n");
  printf("In this post-apocalyptic wasteland, communication is key.\n");
  printf("That's why we need to represent graphs in a unique way.\n");
  
  int nodes = 5;
  int graph[nodes][nodes];
  
  printf("Creating the graph:\n");
  
  // Randomly generating connections between nodes
  for(int i=0; i<nodes; i++) {
    for(int j=0; j<nodes; j++) {
      if(i == j) graph[i][j] = 0; // Node cannot have a connection to itself
      else graph[i][j] = rand() % 2; // Nodes have a 50% chance of being connected
    }
  }
  
  // Printing the graph using post-apocalyptic symbols
  for(int i=0; i<nodes; i++) {
    for(int j=0; j<nodes; j++) {
      if(graph[i][j]) printf("%c--%c ", 178, 178); // 178 represents a block symbol
      else printf("   "); // spaces represent no connection
    }
    printf("\n");
    for(int j=0; j<nodes; j++) {
      if(graph[i][j]) printf("|     "); // | represents a wall symbol
      else printf("      "); // spaces represent no wall
    }
    printf("\n");
  }
}
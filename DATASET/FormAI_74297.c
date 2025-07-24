//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 10; // number of devices in the network
  int adj[n][n];
  srand(time(NULL)); // initialize random seed
  
  // initialize adjacency matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        adj[i][j] = 0; // device cannot connect to itself
      } else {
        adj[i][j] = rand() % 2; // random connection
      }
    }
  }
  
  // print adjacency matrix
  printf("Our network topology:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
  
  // find connected devices to device 0
  printf("Device 0 is connected to devices: ");
  for (int i = 0; i < n; i++) {
    if (adj[0][i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
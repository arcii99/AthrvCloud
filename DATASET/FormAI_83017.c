//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 10

int main() {
  int network[MAX_NODES][MAX_NODES] = {0};
  int num_nodes = 0;

  // Prompt the user to input the number of nodes in the network
  printf("Welcome to the C Network Topology Mapper!\n");
  printf("Please enter the number of nodes in your network (up to %d): ", MAX_NODES);
  scanf("%d", &num_nodes);

  // Prompt the user to input the connectivity of the network
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      int connected;
      printf("Is node %d connected to node %d? (1 for Yes, 0 for No): ", i+1, j+1);
      scanf("%d", &connected);
      if (connected) {
        network[i][j] = 1;
      }
    }
  }

  // Print the network map
  printf("Your network map is:\n");
  printf("   ");
  for (int i = 0; i < num_nodes; i++) {
    printf("%d ", i+1);
  }
  printf("\n");
  for (int i = 0; i < num_nodes; i++) {
    printf("%d: ", i+1);
    for (int j = 0; j < num_nodes; j++) {
      printf("%d ", network[i][j]);
    }
    printf("\n");
  }

  printf("All done! Thanks for trying out the C Network Topology Mapper!\n");

  return 0;
}
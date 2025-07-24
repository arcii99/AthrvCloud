//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello! I'm going to map your network for you!\n");

  // Get input for number of nodes in the network
  int numNodes;
  printf("How many nodes are on your network? ");
  scanf("%d", &numNodes);

  // 2D array to represent the network connections
  int network[numNodes][numNodes];

  // Initialize all connections to 0
  for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
      network[i][j] = 0;
    }
  }

  // Prompt user to input network connections
  printf("Please input the network connections in the format n1,n2\n");
  printf("Enter 'done' when finished\n");

  char input[100];
  int n1, n2;

  // Loop to get all of the connections
  while (1) {
    scanf("%s", input);

    // Check if user is done adding connections
    if (strcmp(input, "done") == 0) {
      break;
    }

    // Split the input into two numbers
    char* ptr;
    ptr = strtok(input, ",");
    n1 = atoi(ptr);
    ptr = strtok(NULL, ",");
    n2 = atoi(ptr);

    // Mark the connection between the nodes in the array
    network[n1][n2] = 1;
    network[n2][n1] = 1;
  }

  // Print out the network topology
  printf("Here is your network topology:\n");
  for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
      printf("%d ", network[i][j]);
    }
    printf("\n");
  }
  
  printf("Yay! I hope you found this helpful! Have a great day!\n");
  return 0;
}
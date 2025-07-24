//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main() {
  // Input the number of devices connected to the network
  int n;
  printf("Enter the number of devices connected to the network: ");
  scanf("%d", &n);

  // Initialize the adjacency matrix and the array of device names
  int matrix[MAX][MAX] = {0};
  char names[n][MAX];
  for (int i = 0; i < n; i++) {
    printf("Enter the name of device %d: ", i+1);
    scanf("%s", names[i]);
  }

  // Manually input the connections between devices
  printf("Enter the connections between devices.\n");
  printf("Separate each number by a space.\n");
  printf("Enter 0 0 to stop.\n");
  int x, y;
  while (1) {
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) break;
    matrix[x-1][y-1] = 1;
    matrix[y-1][x-1] = 1;
  }

  // Print the network topology
  printf("\nNetwork Topology:\n");
  printf("----------------------\n");
  printf("| Device | Connections |\n");
  printf("|--------|-------------|\n");
  for (int i = 0; i < n; i++) {
    printf("| %-6s | ", names[i]);
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("|\n");
  }
  printf("----------------------\n");

  // Calculate the degree of each device
  int degree[MAX] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1) degree[i]++;
    }
  }

  // Print the device degrees
  printf("\nDevice Degrees:\n");
  printf("----------------------\n");
  printf("| Device | Degree |\n");
  printf("|--------|--------|\n");
  for (int i = 0; i < n; i++) {
    printf("| %-6s | %-6d |\n", names[i], degree[i]);
  }
  printf("----------------------\n");

  return 0;
}
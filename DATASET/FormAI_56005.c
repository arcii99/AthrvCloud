//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

int main() {
  printf("Hello there! I am a curious chatbot and I've created a unique graph representation program for you.\n");

  int i, j, n;

  printf("How many vertices do you want to include in the graph? Enter a positive integer: ");
  scanf("%d", &n);

  // Create a 2D array to represent the graph
  int graph[n][n];

  // Initialize all values in the array to 0
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  printf("\nGreat! Please enter the edges in the following format: source_vertex target_vertex (enter -1 -1 to quit)\n");

  int src, target;

  // Ask the user to enter the edges
  while (1) {
    scanf("%d%d", &src, &target);

    if (src == -1 || target == -1) {
      break;
    }

    if (src >= n || target >= n) {
      printf("Invalid vertex! Please enter a vertex between 0 and %d.\n", n - 1);
      continue;
    }

    // Add the edge to the array
    graph[src][target] = 1;
  }

  printf("\nHere is your graph:\n");

  // Print the graph
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  printf("\nThank you for using my program! Stay curious!\n");

  return 0;
}
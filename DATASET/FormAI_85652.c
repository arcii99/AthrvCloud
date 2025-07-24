//FormAI DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>

int main() {
  printf("Welcome to my genius C Graph representation program!\n");

  // Let's create our graph matrix
  int graph[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
  };
  
  // Now let's display our graph
  printf("\n  A B C D E\n");
  printf("  ---------\n");

  for (int i = 0; i < 5; i++) {
    printf("%c|", 'A' + i);
    for (int j = 0; j < 5; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  printf("\nThere you go, your graph is now represented in a 5 x 5 matrix.\n");
  printf("Happy coding!\n");

  return 0;
}
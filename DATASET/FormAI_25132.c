//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>

int main() {
  // Let's create a graph of animals and their characteristics!
  
  // First, we will need to define our graph data structure
  // We will use an adjacency matrix to represent the edges between animals
  int adjMatrix[5][5] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 0, 1, 1, 0}
  };
  
  // Next, we need to define our list of animals
  char animals[5][20] = {
    "Elephant", "Giraffe", "Lion", "Tiger", "Monkey"
  };
  
  // Now, we can print out our graph
  printf("List of animals and their characteristics:\n\n");
  for (int i = 0; i < 5; i++) {
    printf("%s:\n", animals[i]);
    for (int j = 0; j < 5; j++) {
      if (adjMatrix[i][j] == 1) {
        switch(j) {
          case 0:
            printf("  - Large ears\n");
            printf("  - Big body\n");
            printf("  - Trunk\n");
            break;
          case 1:
            printf("  - Long neck\n");
            printf("  - Spotted skin\n");
            break;
          case 2:
            printf("  - Mane\n");
            printf("  - Sharp claws\n");
            break;
          case 3:
            printf("  - Stripes\n");
            printf("  - Large paws\n");
            break;
          case 4:
            printf("  - Small size\n");
            printf("  - Long tail\n");
            printf("  - Playful\n");
            break;
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}
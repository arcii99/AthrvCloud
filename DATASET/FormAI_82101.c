//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include <stdio.h>

int main() {

  printf("Welcome to my cheerful C Graph representation program!\n");

  // Initializing vertices
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  // Printing vertices
  printf("Vertices: %d, %d, %d, %d\n", v1, v2, v3, v4);

  // Initializing edges
  int e12 = 1;
  int e13 = 1;
  int e23 = 1;
  int e24 = 1;
  int e34 = 1;

  // Printing edges
  printf("Edges:\n%d -> %d\n%d -> %d\n%d -> %d\n%d -> %d\n%d -> %d\n", v1, v2, v1, v3, v2, v3, v2, v4, v3, v4);

  // Initializing matrix
  int matrix[4][4] = {{0, e12, e13, 0},
                      {e12, 0, e23, e24},
                      {e13, e23, 0, e34},
                      {0, e24, e34, 0}};

  // Printing matrix
  printf("Matrix:\n   1  2  3  4\n");
  for (int i = 0; i < 4; i++) {
      printf("%d ", i + 1);
      for (int j = 0; j < 4; j++) {
          printf("%2d ", matrix[i][j]);
      }
      printf("\n");
  }

  printf("Thanks for using my C Graph representation program!\n");

  return 0;
}
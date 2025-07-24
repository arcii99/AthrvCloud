//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>

void fractal(int depth, int numSpaces) {
  if (depth == 0) {
    // Base case: print out the spaces and the character
    for (int i = 0; i < numSpaces; i++) {
      printf(" ");
    }
    printf("*\n");
  } else {
    // Recursive case: call fractal for sub-trees
    for (int i = 0; i < numSpaces; i++) {
      printf(" ");
    }
    printf("+\n");
    fractal(depth - 1, numSpaces + 3);
    for (int i = 0; i < numSpaces; i++) {
      printf(" ");
    }
    printf("|\n");
    fractal(depth - 1, numSpaces + 3);
    for (int i = 0; i < numSpaces; i++) {
      printf(" ");
    }
    printf("+\n");
  }
}

int main() {
  // Prompt user for depth of fractal
  int depth;
  printf("Enter depth of fractal: ");
  scanf("%d", &depth);

  // Print the fractal
  fractal(depth, 0);

  return 0;
}
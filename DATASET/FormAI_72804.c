//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {

  // Determine the size of the pattern
  int size;
  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  // Loop through rows of the pattern
  for (int i = 1; i <= size; i++) {

    // Print spaces before the characters
    for (int j = 1; j <= size - i; j++) {
      printf(" ");
    }

    // Print the characters in increasing order
    for (int k = 1; k <= i; k++) {
      printf("%d", k);
    }

    // Print the characters in decreasing order
    for (int l = i - 1; l >= 1; l--) {
      printf("%d", l);
    }

    printf("\n");
  }

  return 0;
}
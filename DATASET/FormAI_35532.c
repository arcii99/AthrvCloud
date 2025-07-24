//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main() {
  int n, i, j, k;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Print the top half of the pattern
  for (i = 1; i <= n/2; i++) {
    // Print the spaces before the C
    for (j = i; j < n/2; j++) {
      printf(" ");
    }
    // Print the C
    printf("C");
    // Print the spaces inside the C
    for (k = 1; k < 2*i-1; k++) {
      printf(" ");
    }
    // Print the C again
    printf("C\n");
  }

  // Print the middle row of the pattern
  for (i = 1; i <= n/2; i++) {
    printf(" ");
  }
  printf("C\n");

  // Print the bottom half of the pattern
  for (i = n/2; i >= 1; i--) {
    // Print the spaces before the C
    for (j = n/2; j > i; j--) {
      printf(" ");
    }
    // Print the C
    printf("C");
    // Print the spaces inside the C
    for (k = 1; k < 2*i-1; k++) {
      printf(" ");
    }
    // Print the C again
    printf("C\n");
  }

  return 0;
}
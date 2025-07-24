//FormAI DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>

int main() {
  int i, j, k;

  // User input for pattern size
  printf("Enter the size of the pattern: ");
  scanf("%d", &k);

  for (i = k; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  for (i = 2; i <= k; i++) {
    for (j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  return 0;
}
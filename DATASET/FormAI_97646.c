//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
  int i, j, k, n;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      printf("*");
    }

    for (k = 0; k < i; k++) {
      printf("  ");
    }

    for (j = 0; j < n - i; j++) {
      printf("*");
    }

    printf("\n");
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
      printf("*");
    }

    for (k = 0; k < n - i - 1; k++) {
      printf("  ");
    }

    for (j = 0; j <= i; j++) {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}
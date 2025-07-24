//FormAI DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

int main() {
  int n, i, j, k;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
        printf("* ");
      } else if (i == j) {
        printf("\\ ");
      } else if (i + j == n - 1) {
        printf("/ ");
      } else if (j >= i && j + i <= n - 1) {
        printf("^ ");
      } else if (j <= i && j + i >= n - 1) {
        printf("v ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}
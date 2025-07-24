//FormAI DATASET v1.0 Category: Pattern printing ; Style: artistic
#include <stdio.h>

int main() {
  int n = 9; // Change this value to change the size of the pattern
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < 2 * n - 1; j++) {
      if (j == n - i || j == n + i - 2) {
        printf("*");
      } else if (j > n - i && j < n + i - 2) {
        if ((i + j) % 2 == 0) {
          printf("*");
        } else {
          printf(" ");
        }
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      if (j == n - i || j == n + i - 2) {
        printf("*");
      } else if (j > n - i && j < n + i - 2) {
        if ((i + j) % 2 == 0) {
          printf("*");
        } else {
          printf(" ");
        }
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
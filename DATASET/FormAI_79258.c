//FormAI DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include <stdio.h>

int main() {
  int x, y, n;
  printf("Let's print a C-shaped pattern. How many rows do you want? ");
  scanf("%d", &n);
  for (x = 0; x < n; x++) {
    for (y = 0; y <= n; y++) {
      if (y == 0 || (x == 0 && y < n) || (x == n/2 && y >= n/2) || (y == n/2 && x > n/2) || x == n-1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
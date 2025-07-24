//FormAI DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>

int main() {
  int n, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("*");
    }
    for (j = i+1; j <= n; j++) {
      printf(" ");
    }
    for (j = n-1; j >= i; j--) {
      printf("*");
    }
    for (j = i-1; j >= 1; j--) {
      printf(" ");
    }
    printf("\n");
  }

  for (i = n-1; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("*");
    }
    for (j = i+1; j <= n; j++) {
      printf(" ");
    }
    for (j = n-1; j >= i; j--) {
      printf("*");
    }
    for (j = i-1; j >= 1; j--) {
      printf(" ");
    }
    printf("\n");
  }

  return 0;
}
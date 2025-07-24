//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main() {
  int n, i, j, k;
  printf("Enter the number of rows you want in this pattern: ");
  scanf("%d", &n);
  
  // Upper half
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n-i; j++) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }
  
  // Lower half
  for (i = n-1; i >= 1; i--) {
    for (j = 1; j <= n-i; j++) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }
  
  return 0;
}
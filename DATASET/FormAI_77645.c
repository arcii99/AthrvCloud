//FormAI DATASET v1.0 Category: Pattern printing ; Style: visionary
#include<stdio.h>

int main() {
  int n, i, j, k;
  printf("Enter the number of rows (odd number): ");
  scanf("%d", &n);

  // Rows for the upper half
  for(i = 1; i <= (n+1)/2; i++) {
    for(j = 1; j <= ((n+1)/2) - i; j++) {
      printf(" ");
    }

    for(k = 1; k <= (2 * i) - 1; k++) {
      printf("*");
    }

    printf("\n");
  }

  // Rows for the lower half
  for(i = (n-1)/2; i >= 1; i--) {
    for(j = 1; j <= ((n+1)/2) - i; j++) {
      printf(" ");
    }

    for(k = 1; k <= (2 * i) - 1; k++) {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}
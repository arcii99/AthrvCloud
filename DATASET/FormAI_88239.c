//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include<stdio.h>

int main() {
  int n, i, j, k, x;

  printf("Enter the number of rows (odd number): ");
  scanf("%d", &n);

  if(n % 2 == 1) {
    x = (n / 2) + 1;

    for(i = 1; i <= n; i++) {
      if(i <= x) {
        for(k = x; k > i; k--) {
          printf(" ");
        }
        for(j = 1; j <= (2 * i) - 1; j++) {
          printf("*");
        }
        printf("\n");
      } 
      else {
        for(k = x; k <= i; k++) {
          printf(" ");
        }
        for(j = (2 * (n - i)) + 1; j >= 1; j--) {
          printf("*");
        }
        printf("\n");
      }
    }
  } 
  else {
    printf("Please enter an odd number!\n");
  }

  return 0;
}
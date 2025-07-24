//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
  int n, i, j, k;

  printf("Enter a number: ");
  scanf("%d", &n);
  
  printf("\nLook at this magnificent pattern:\n\n");

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n-i; j++) {
      printf(" ");
    }
    for (k = 1; k <= (2*i - 1); k++) {
      printf("*");
    }
    printf("\n");
  }
  
  printf("\nDid you see it? This is the most amazing C Pattern you've ever seen!\n");

  return 0;
}
//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>

int main() {
  int i, j, num;
  printf("Enter a number: ");
  scanf("%d", &num);

  // Loop to print the upper triangle
  for (i = 1; i <= num; i++) {
    for (j = i; j < num; j++) {
      printf(" ");
    }
    for (j = 1; j <= (2 * i - 1); j++) {
      printf("*");
    }
    printf("\n");
  }

  // Loop to print the lower triangle
  for (i = num - 1; i >= 1; i--) {
    for (j = 0; j < num - i; j++) {
      printf(" ");
    }
    for (j = 1; j <= (2 * i - 1); j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
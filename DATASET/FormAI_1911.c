//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

void printDiamond(int n) {
  if (n <= 0) {
    printf("Cannot generate diamond with size <= 0\n");
    return;
  }
  int i, j, k;

  // Upper half of the diamond
  for (i = 0; i < n; i++) {
    for (j = i; j < n - 1; j++) {
      printf(" ");
    }
    for (k = 0; k < 2 * i + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  // Lower half of the diamond
  for (i = n - 2; i >= 0; i--) {
    for (j = n - 1; j > i; j--) {
      printf(" ");
    }
    for (k = 2 * i + 1; k > 0; k--) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  printf("Let's create a diamond!\n");
  printf("Please enter the size of the diamond: ");
  int size;
  scanf("%d", &size);
  printf("\n");
  printDiamond(size);
  printf("\n");
  printf("Thanks for using my program! Goodbye :)\n");
  return 0;
}
//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
  int n, i, j;

  printf("Enter the number of lines in the pattern: ");
  scanf("%d", &n);

  printf("Here's your pattern, wow!\n");

  // Upper half of the pattern
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  // Lower half of the pattern
  for(i = n-1; i >= 1; i--) {
    for(j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("It's like magic!\n");

  return 0;
}
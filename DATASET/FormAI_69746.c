//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

int main() {
  int num, i, j, k;
  printf("Enter number of rows in the pattern: ");
  scanf("%d", &num);
  for (i = 1; i <= num; i++) {  // for loop for rows
    for (j = num - i; j >= 1; j--) {  // for loop for spaces
      printf(" ");
    }
    for (k = 1; k <= 2 * i - 1; k++) {  // for loop for stars
      printf("*");
    }
    printf("\n");  // Next line
  }
  return 0;
}
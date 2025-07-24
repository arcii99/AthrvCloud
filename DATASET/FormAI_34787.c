//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>

int main() {
  int num1, num2, sum;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;

  printf("\n");
  printf("Surprise! The sum of %d and %d is %d.\n", num1, num2, sum);

  if (sum > 100) {
    printf("Holy cow! That's a big number!\n");
  } else if (sum > 50) {
    printf("Wow, that's getting up there!\n");
  } else {
    printf("Hmm, not too shabby!\n");
  }

  return 0;
}
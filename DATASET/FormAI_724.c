//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

int recursive_sum(int num) {

  /* Base Case */
  if (num == 1) {
    return 1;
  }

  /* Recursive Case */
  else {
    return num + recursive_sum(num - 1);
  }
}

int main() {
  int num;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  if (num <= 0) {
    printf("Input must be positive.\n");
  }

  else {
    printf("The sum of integers from 1 to %d is %d.\n", num, recursive_sum(num));
  }

  return 0;
}
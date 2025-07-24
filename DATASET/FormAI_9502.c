//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

int factorial(int num) {
  // base case
  if (num == 0) {
    return 1;
  }
  // recursive case
  else {
    return num * factorial(num - 1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("The factorial of %d is %d\n", num, factorial(num));
  return 0;
}
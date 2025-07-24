//FormAI DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>

int fibonacci(int n) {
  // base cases
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  // recursive case
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int number = 7;
  int result = fibonacci(number);
  printf("The %dth fibonacci sequence number is %d. \n", number, result);
  return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

int fibonacci(int n) {
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  printf("The %d-th number in the Fibonacci sequence is %d\n", num, fibonacci(num));

  return 0;
}
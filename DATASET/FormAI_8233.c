//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>

// recursive function to calculate the factorial of a number
int factorial(int num) {
  if (num == 0) {  // base case: factorial of 0 is 1
    return 1;
  } else {
    return num * factorial(num - 1);  // recursive call with num-1
  }
}

int main() {
  int n = 5;  // calculate factorial of 5
  printf("The factorial of %d is %d\n", n, factorial(n));
  return 0;
}
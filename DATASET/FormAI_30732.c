//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

int factorial(int num) {
  if (num == 1 || num == 0) {                   // base case
    return 1;
  } else {
    return num * factorial(num - 1);           // recursive call
  }
}

int main() {
  int num = 5;
  int result = factorial(num);
  
  printf("Factorial of %d is %d\n", num, result);
  
  return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: distributed
#include <stdio.h>

int recursiveFunction(int n) {
  if(n == 0) {
    return 0;
  } else {
    return n + recursiveFunction(n-1);
  }
}

int main(void) {
  int n = 5;
  int result = recursiveFunction(n);

  printf("The sum of the numbers from 1 to %d is: %d", n, result);

  return 0;
}
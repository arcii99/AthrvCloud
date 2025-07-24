//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

int recursive_factorial(int n) {
  if(n == 0 || n == 1) { // base case
    return 1;
  } else {
    return n * recursive_factorial(n - 1); // recursive call
  }
}

int main() {
  int num;
  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);
  if(num >= 0) {
    int result = recursive_factorial(num);
    printf("The factorial of %d is: %d\n", num, result);
  } else {
    printf("Invalid input! Number must be non-negative.\n");
  }
  return 0;
}
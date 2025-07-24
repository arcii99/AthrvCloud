//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

int recursiveFunction(int num1, int num2) {
  if (num1 == 0 || num2 == 0) {
    return 0;
  }
  else if (num1 % num2 == 0) {
    return num2;
  }
  else {
    return recursiveFunction(num2, num1 % num2);
  }
}

int main() {
  int num1, num2, gcd;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  if (num1 < num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
  }

  gcd = recursiveFunction(num1, num2);
  printf("GCD of %d and %d is: %d", num1, num2, gcd);

  return 0;
}
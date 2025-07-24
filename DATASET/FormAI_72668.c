//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

int main() {
  // print out the first ten even numbers
  for (int i = 0; i < 20; i += 2) {
    printf("%d ", i);
  }
  
  printf("\n");
  
  // calculate the sum of the first ten odd numbers
  int sum = 0;
  for (int i = 1; i < 20; i += 2) {
    sum += i;
  }
  
  printf("The sum of the first ten odd numbers is: %d\n", sum);
  
  // find the smallest prime factor of a number
  int n = 15;
  int smallest_factor = -1;
  
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      smallest_factor = i;
      break;
    }
  }
  
  if (smallest_factor == -1) {
    printf("%d is a prime number.\n", n);
  } else {
    printf("%d is not a prime number. Its smallest factor is: %d\n", n, smallest_factor);
  }
  
  // calculate the factorial of a number
  int num = 5;
  int factorial = 1;
  
  for (int i = 1; i <= num; i++) {
    factorial *= i;
  }
  
  printf("The factorial of %d is: %d\n", num, factorial);
  
  return 0;
}
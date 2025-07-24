//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

int main() {
  // Prompt user for input
  printf("Enter a number to add to itself: ");

  // Declare variables
  int num;
  scanf("%d", &num);

  // Calculate result
  int result = num + num;

  // Print result
  printf("%d + %d = %d\n", num, num, result);

  // Check for negative numbers
  if (num < 0) {
    printf("%d is a negative number\n", num);
  }

  // Check for even or odd
  if (num % 2 == 0) {
    printf("%d is an even number\n", num);
  } else {
    printf("%d is an odd number\n", num);
  }

  // Check if number is a prime number
  int i, flag = 0;
  for (i = 2; i <= num / 2; ++i) {
    // condition for non-prime
    if (num % i == 0) {
      flag = 1;
      break;
    }
  }

  if (num == 1) {
    printf("1 is neither prime nor composite\n");
  } else {
    if (flag == 0)
      printf("%d is a prime number\n", num);
    else
      printf("%d is not a prime number\n", num);
  }

  // Calculate factorial
  int j, fact = 1;
  for (j = 1; j <= num; j++) {
    fact = fact * j;
  }
  printf("Factorial of %d is %d\n", num, fact);

  return 0;
}
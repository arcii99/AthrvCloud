//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>

// Let's write a program to find the factorial of a number using recursion.
// Wohoo! Are you ready? Let's go!

int factorial(int n) {
  // The base case of recursion is when n is equal to 1 or 0.
  if (n <= 1) {
    return 1;
  }

  // If n is not 1 or 0, then we calculate the factorial recursively.
  int fact = n * factorial(n - 1);
  return fact;
}

int main() {
  // Let's ask the user for a number to calculate the factorial of.
  printf("Hey there! Let's find the factorial of a number using recursion! \n");
  printf("Please enter a positive integer: ");

  int num;
  scanf("%d", &num);

  // Let's print the result of our calculation.
  printf("The factorial of %d is %d. Woohoo!\n", num, factorial(num));

  return 0;
}

// There you go! We just wrote a program that calculates the factorial of a number using recursion. Keep coding, my friend!
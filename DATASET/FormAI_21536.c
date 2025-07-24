//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

// Declare a function to check if a number is positive or negative
void checkNumber(int num) {
  if (num >= 0) {
    printf("%d is a positive number!\n", num);
  } else {
    printf("%d is a negative number!\n", num);
  }
}

int main() {
  // Declare and initialize variables
  int a = 10, b = -5, c = 0;
  float f1 = 3.14, f2 = -2.5;

  // Welcome message
  printf("Welcome to the Positive or Negative Checker program!\n");

  // Call function to check variables
  checkNumber(a);
  checkNumber(b);
  checkNumber(c);
  checkNumber((int)f1);
  checkNumber((int)f2);

  // End message
  printf("Thank you for checking your numbers with us!\n");

  // Return 0 to indicate success
  return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

int factorial(int num) {
  if (num == 1) {
    return 1;
  } else {
    return num * factorial(num-1);
  }
}

int main() {
  int number;
  printf("Welcome! This program calculates the factorial of any number.\n");
  printf("Please enter a positive integer: ");
  scanf("%d", &number);
  printf("Number %d factorial is equal to: %d\n", number, factorial(number));
  printf("Thank you for using this program!\n");
  return 0;
}
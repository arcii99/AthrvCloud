//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

int factorial(int num) {

  // Base Case
  if (num == 0) {
    return 1;
  }

  // Recursive Case
  else {
    return num * factorial(num - 1);
  }

}

int main() {

  int num;

  printf("Enter a non-negative integer: ");
  scanf("%d", &num);

  // Check if user entered a non-negative integer
  if (num < 0) {
    printf("Please enter a non-negative integer!\n");
  }

  // Call the factorial function if user entered a non-negative integer
  else {
    int fact = factorial(num);
    printf("%d! = %d\n", num, fact);
  }

  return 0;

}
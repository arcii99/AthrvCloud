//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>

int main() {
  // Declare variables
  int num1, num2, sum;
  
  // Ask user for input
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  
  // Calculate sum
  sum = num1 + num2;
  
  // Display result
  if (sum > 0 && sum <= 10) {
    printf("Good job! Your sum is between 0 and 10.\n");
  } else if (sum > 10 && sum <= 50) {
    printf("Well done! Your sum is between 10 and 50.\n");
  } else if (sum > 50 && sum <= 100) {
    printf("Amazing! Your sum is between 50 and 100.\n");
  } else {
    printf("Oops! Your sum is larger than 100.\n");
  }
  
  return 0;
}
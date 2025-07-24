//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, product, quotient;
  
  printf("Welcome to my Arithmetic Program!\n");
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  sum = num1 + num2;
  diff = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  
  printf("\nThe sum of %d and %d is: %d", num1, num2, sum);
  printf("\nThe difference between %d and %d is: %d", num1, num2, diff);
  printf("\nThe product of %d and %d is: %d", num1, num2, product);
  printf("\nThe quotient of %d and %d is: %d", num1, num2, quotient);
  
  printf("\n\nThank you for using my program!\n");
  
  return 0;
}
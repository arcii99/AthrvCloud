//FormAI DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod, quo, mod;
  
  printf("Hello there! I hope you're doing well. Let's get started on some arithmetic calculations!\n\n");
  
  /* Asking for user input */
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  /* Arithmetic operations */
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quo = num1 / num2;
  mod = num1 % num2;
  
  /* Displaying the results */
  printf("\nGreat job! Here are the results:\n");
  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", diff);
  printf("Product: %d\n", prod);
  
  if(num2 != 0) {
    printf("Quotient: %d\n", quo);
    printf("Modulus: %d\n", mod);
  } else {
    printf("Cannot divide by zero. Please enter a non-zero second number.\n");
  }
  
  printf("\nThanks for using this program. Hope you come back soon!\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>

int main() {
  int num1, num2, sum, product;
  
  printf("Please enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  // Add two numbers and print the result
  sum = num1 + num2;
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  
  // Multiply two numbers and print the result
  product = num1 * num2;
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  
  // Find the difference between two numbers
  if (num1 > num2) {
    printf("The difference between %d and %d is %d.\n", num1, num2, num1 - num2);
  } else {
    printf("The difference between %d and %d is %d.\n", num2, num1, num2 - num1);
  }
  
  // Determine if the numbers are equal or not
  if (num1 == num2) {
    printf("%d and %d are equal.\n", num1, num2);
  } else {
    printf("%d and %d are not equal.\n", num1, num2);
  }
  
  return 0;
}
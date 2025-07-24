//FormAI DATASET v1.0 Category: Educational ; Style: Alan Touring
#include <stdio.h>

int main() {
  int num1, num2, sum, product;
  
  // Get input from the user
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Enter another number: ");
  scanf("%d", &num2);
  
  // Perform calculations
  sum = num1 + num2;
  product = num1 * num2;
  
  // Print out results
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  
  // Check if either number is even
  if (num1 % 2 == 0 || num2 % 2 == 0) {
    printf("At least one of the numbers is even.\n");
  } else {
    printf("Neither of the numbers are even.\n");
  }
  
  // Check if either number is a multiple of 7
  if (num1 % 7 == 0 || num2 % 7 == 0) {
    printf("At least one of the numbers is a multiple of 7.\n");
  } else {
    printf("Neither of the numbers are multiples of 7.\n");
  }
  
  // Check which number is larger
  if (num1 > num2) {
    printf("%d is larger than %d.\n", num1, num2);
  } else if (num2 > num1) {
    printf("%d is larger than %d.\n", num2, num1);
  } else {
    printf("The two numbers are equal.\n");
  }
  
  return 0;
}
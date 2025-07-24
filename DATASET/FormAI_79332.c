//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>

int main() {

  int num1, num2, sum, difference, product, quotient;

  //Requesting for input numbers from the user
  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  //Arithmetic operations
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;

  //Checking if second number is not equal to zero
  if(num2 != 0) {
    quotient = num1 / num2;
  }
  else {
    printf("Oops! Cannot perform division as second number is zero.\n");
    //Exit if the division could not be performed
    return 0;
  }

  //Displaying results of all arithmetic operations
  printf("\nResult of %d + %d is: %d", num1, num2, sum);
  printf("\nResult of %d - %d is: %d", num1, num2, difference);
  printf("\nResult of %d * %d is: %d", num1, num2, product);

  //Checking if the quotient was possible or not
  if(num2 != 0) {
    printf("\nResult of %d / %d is: %d", num1, num2, quotient);
  }

  printf("\n\n");

  return 0;

}
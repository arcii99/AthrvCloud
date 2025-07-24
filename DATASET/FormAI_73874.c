//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>

int main() {

  int x, y;

  //asking user for input values
  printf("Let's make some math! \nPlease enter two numbers: \n");
  scanf("%d %d", &x, &y);

  //performing mathematical operations and handling errors
  if(y == 0) {
    printf("Oops! Something went wrong, division by zero is not allowed. Please try again!\n");
    return 1; //returning non-zero value to indicate an error occured
  }
  else {
    int sum, diff, prod, div; //declaring variables
    sum = x + y; //performing addition
    diff = x - y; //performing subtraction
    prod = x * y; //performing multiplication
    div = x / y; //performing division

    //displaying the results
    printf("The sum of %d and %d is: %d \n", x, y, sum);
    printf("The difference between %d and %d is: %d \n", x, y, diff);
    printf("The product of %d and %d is: %d \n", x, y, prod);
    printf("The result of dividing %d by %d is: %d \n", x, y, div);
  }
  
  return 0; //returning zero to indicate successful program completion 
}
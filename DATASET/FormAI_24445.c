//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dividend, divisor, result;
  
  printf("Enter the dividend: ");
  if(scanf("%d", &dividend) != 1) { // check if input is valid
    printf("Invalid input for dividend!");
    return 1; // terminate program with error code 1
  }
  
  printf("Enter the divisor: ");
  if(scanf("%d", &divisor) != 1) { // check if input is valid
    printf("Invalid input for divisor!");
    return 1; // terminate program with error code 1
  }
  
  if(divisor == 0) { // check for division by zero
    printf("Cannot divide by zero!");
    return 1; // terminate program with error code 1
  }
  
  result = dividend / divisor; // perform division
  
  printf("%d divided by %d is %d\n", dividend, divisor, result);
  
  return 0; // terminate program
}
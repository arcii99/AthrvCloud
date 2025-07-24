//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  // declare variables
  int num1, num2, result;
  
  // ask user for input
  printf("Enter First Number: ");
  scanf("%d", &num1);
  
  printf("Enter Second Number: ");
  scanf("%d", &num2);
  
  // handle error if second number entered is 0
  if(num2 == 0) {
      printf("ERROR: Division by zero is undefined!\n");
      printf("Maybe try a non-zero number next time?\n");
      exit(1); // terminate program
  }

  // calculate division and print result
  result = num1 / num2;
  printf("%d divided by %d is %d\n", num1, num2, result);

  return 0;
}
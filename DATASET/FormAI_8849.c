//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
/* 
Author: Peaceful Programmer 
Created on: Today 
A serene program that parses C syntax
*/

#include<stdio.h>

int main() {
  printf("Welcome to C Syntax Parser!\n"); // peaceful greeting 

  // peaceful declaration
  int num1 = 10;
  int num2 = 20;
  int result = num1 + num2;
  
  // peaceful message
  printf("The result of %d + %d is %d.\n", num1, num2, result);

  // peaceful conditional statement  
  if(result > 25) {
    printf("The sum is greater than 25.\n");
  } else {
    printf("The sum is less than or equal to 25.\n");
  }

  // peaceful loop statement
  int i;
  for(i = 0; i < 10; i++) {
    printf("%d ", i);
  }

  // peaceful switch statement
  char grade = 'A';
  switch(grade) {
    case 'A':
      printf("\nYou got an A grade. Congrats!\n");
      break;
    case 'B':
      printf("\nYou got a B grade. Good job!\n");
      break;
    case 'C':
      printf("\nYou got a C grade. Keep working hard.\n");
      break;
    default:
      printf("\nSorry, you did not pass the exam.\n");
  }

  // peaceful function call
  int value = max(10, 20);
  printf("\nThe maximum value is %d.\n", value);

  return 0;
}

// peaceful function definition
int max(int num1, int num2) {
  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }
}
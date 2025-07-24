//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h> // Include the standard input-output header file
#include <stdlib.h> // Include the standard library header file

// Function to divide two numbers
int divide(int a, int b){
  if(b==0){ // Check if denominator is zero
    printf("Division by zero error!\n");
    exit(0); // Exit the program with status code 0
  }
  return a/b;
}

int main(){
  int num1, num2;

  printf("Enter two numbers for division:\n");
  scanf("%d %d", &num1, &num2); // Take input from user

  int result = divide(num1, num2);

  printf("Result = %d\n", result);

  return 0;
}
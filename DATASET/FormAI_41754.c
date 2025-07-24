//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b){
  if(b == 0){
    //throw error if denominator is zero
    printf("Error: Divide by zero has occurred.\n");
    exit(EXIT_FAILURE);
  }
  return a/b;
}

int main(){
  int num1, num2;
  printf("Enter two numbers to divide: ");
  scanf("%d %d", &num1, &num2);

  int result;
  //try block
  printf("Trying to divide %d by %d..\n", num1, num2);
  result = divide(num1, num2);
  printf("Division Result: %d\n", result);

  //catch block
  printf("Program is still running.\n");

  return 0;
}
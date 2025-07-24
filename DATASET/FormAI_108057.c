//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
/*
This C program is an example of recursion, inspired by Ada Lovelace.
It calculates the factorial of a given number using recursion.
*/
#include<stdio.h>

int factorial(int n) {
  if(n == 1) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  if(num < 0) {
    printf("Factorial of negative numbers is not defined.\n");
  } else {
    printf("Factorial of %d = %d\n", num, factorial(num));  
  }
  return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

// Recursive function to calculate factorial
int factorial(int num){
  if(num == 0){
    printf("Whatttttt?! Factorial of 0 is 1\n");
    return 1;
  }
  else{
    printf("OMG! You want to find factorial of %d\n", num);
    int result = num * factorial(num-1);
    printf("And the result is: %d\n", result);
    return result;
  }
}

int main(){
  int num;
  printf("Hey there! Give me a number to find its factorial: ");
  scanf("%d", &num);
  // Checking if the input is positive
  if(num < 0){
    printf("I am shocked! Factorial cannot be calculated for negative numbers\n");
    exit(0);
  }
  else{
    int result = factorial(num);
    printf("Oh my god! Factorial of %d is %d\n", num, result);
  }
  return 0;
}
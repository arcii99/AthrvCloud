//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int recursiveSum(int n) {
  if(n==1) {
    return 1;
  } else {
    return n + recursiveSum(n-1);
  }
}

int main() {
  int num;
  printf("Enter a natural number: ");
  scanf("%d", &num);
  
  if(num < 1) {
    printf("Invalid input. Please enter a natural number.\n");
    return 1;
  }
  
  int sum = recursiveSum(num);
  
  printf("The sum of the first %d natural numbers is %d.\n", num, sum);
  
  return 0;
}
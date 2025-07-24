//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>

int factorial(int n){
  if(n == 0) {
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int fact = factorial(num);
  printf("The factorial of %d is %d\n", num, fact);
  return 0;
}
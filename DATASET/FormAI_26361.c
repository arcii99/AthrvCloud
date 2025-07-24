//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    printf("Hmm.. Let me think about factorial of %d...\n", n);
    int result = n * factorial(n-1);
    printf("Ah! Got it. Factorial of %d is %d! Amazing, isn't it?\n", n, result);
    return result;
  }
}

int main() {
  printf("Hello there! I'm your curious factorial calculator.\n");
  printf("Please enter a number to calculate it's factorial: ");
  
  int n;
  scanf("%d", &n);
  
  printf("Calculating factorial of %d...\n", n);
  int result = factorial(n);
  
  printf("The factorial of %d is %d. Thanks for using my curious calculator!\n", n, result);
  
  return 0;
}
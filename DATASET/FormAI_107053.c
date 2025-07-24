//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

int count(int n) {
  // Base case: if n is 0, return 0
  if(n == 0) {
    return 0;
  }
  // Recursive case: return the sum of digits
  return n % 10 + count(n / 10);
}

int main() {
  printf("Enter a positive integer: ");
  int n;
  scanf("%d", &n);
  
  // If n is negative, prompt again until positive number is entered
  while(n < 0) {
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
  }
  
  // Call the recursive function and print the result
  int result = count(n);
  printf("The sum of digits in %d is %d.\n", n, result);
  
  return 0;
}
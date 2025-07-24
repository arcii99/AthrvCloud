//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int main() {
  int i, j, n, isPrime;
  
  printf("Enter a number greater than 1: ");
  scanf("%d", &n);
  
  if(n <= 1) {
    printf("Invalid input. Please enter a number greater than 1.\n");
    return 0;
  }
  
  printf("The prime numbers between 2 and %d are:\n", n);
  
  for(i = 2; i <= n; i++) {
    isPrime = 1; /* Assume number is prime */
    
    for(j = 2; j < i; j++) {
      if(i % j == 0) {
        isPrime = 0; /* Number is not prime */
        break;
      }
    }
    
    if(isPrime) {
      printf("%d ", i);
    }
  }
  
  printf("\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
/*
 * Description: This program generates prime numbers up to a user-specified limit
 * Author: Claude Shannon
 * Date: March 1st, 1951
 */

#include <stdio.h>

int main() {
  int limit, i, j, is_prime;
  
  // Get user input for limit
  printf("Enter the limit for prime numbers: ");
  scanf("%d", &limit);
  
  // Handle edge cases for 0 and 1
  if(limit == 0 || limit == 1) {
    printf("No prime numbers exist for the given limit\n");
    return 0;
  }
  
  // Generate a list of prime numbers up to the limit
  printf("Prime numbers up to %d are: ", limit);
  for(i = 2; i <= limit; i++) {
    is_prime = 1;
    for(j = 2; j <= i / 2; j++) {
      if(i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if(is_prime) {
      printf("%d ", i);
    }
  }
  printf("\n");
  
  return 0;
}
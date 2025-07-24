//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
  int limit;

  printf("Enter the limit for prime number generation: ");
  scanf("%d", &limit);

  printf("The prime numbers up to %d are:\n", limit);

  for(int i = 2; i <= limit; i++) {
    if(is_prime(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}

bool is_prime(int num) {
  if(num == 2) {
    return true;
  } else if(num < 2 || num % 2 == 0) {
    return false;
  }

  int divisor = 3;

  while(divisor * divisor <= num) {
    if (num % divisor == 0) {
      return false;
    }
    
    divisor += 2;
  }

  return true;
}
//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }
  
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int primes[1000];
  int count = 0;
  int sum = 0;
  
  for (int i = 2; count < 1000; i++) {
    if (is_prime(i)) {
      primes[count] = i;
      sum += i;
      count++;
    }
  }
  
  printf("The sum of the first 1000 prime numbers is: %d\n", sum);
  
  return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>

int is_prime(int n) {
  if (n < 2) {
      return 0;
  }
  for (int i = 2; i < n; i++) {
      if (n % i == 0) {
          return 0;
      }
  }
  return 1;
}

int main() {
  int n, count = 0;
  
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &n);
  
  printf("First %d prime numbers are: ", n);
  
  for (int i = 2; count < n; i++) {
      if (is_prime(i)) {
          printf("%d ", i);
          count++;
      }
  }
  
  return 0;
}
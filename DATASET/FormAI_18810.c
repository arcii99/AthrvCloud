//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
  if(num <= 1) {
    return false;
  }
  
  for(int i = 2; i <= num/2; i++) {
    if(num % i == 0) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int n, count = 0;
  
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);
  
  printf("The first %d prime numbers are:\n", n);
  
  for(int i = 2; count < n; i++) {
    if(is_prime(i)) {
      printf("%d, ", i);
      count++;
    }
  }
  
  printf("\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if(n <= 1) {
    return false;
  }
  for(int i = 2; i <= n/2; i++) {
    if(n%i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, count = 0;

  printf("Enter the range: ");
  scanf("%d", &n);

  printf("Prime numbers within the range are: \n");

  for(int i = 2; i <= n; i++) {
    if(isPrime(i)) {
      count++;
      printf("%d ", i);
    }
  }

  printf("\n\nTotal number of prime numbers within the range: %d\n", count);

  return 0;
}
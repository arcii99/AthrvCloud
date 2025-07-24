//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int limit;
  printf("Enter the maximum number up to which you want to generate prime numbers: ");
  scanf("%d", &limit);
  printf("The prime numbers from 1 to %d are: \n", limit);
  for (int i = 2; i < limit; i++) {
    if (isPrime(i)) printf("%d\n", i);
  }
  return 0;
}
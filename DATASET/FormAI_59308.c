//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  printf("Welcome to the Prime Number Generator!\n");
  printf("Please enter an integer greater than or equal to 2:\n");
  int n;
  scanf("%d", &n);
  printf("Generating prime numbers up to %d...\n", n);
  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) printf("%d ", i);
  }
  printf("\n");
  printf("Thank you for using the Prime Number Generator!\n");
  return 0;
}
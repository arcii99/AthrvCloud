//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>

int is_prime(int num);

int main() {
  int n;
  printf("Enter the upper limit for prime numbers to be generated: ");
  scanf("%d", &n);
  printf("The prime numbers between 1 and %d are:\n", n);
  
  for (int i = 2; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}

int is_prime(int num) {
  if (num < 2) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int isPrime(int num) {
  if (num < 2) return 0;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

int main() {
  int max_num = 100;
  printf("Prime numbers between 1 and %d are:\n", max_num);
  for (int i = 1; i <= max_num; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
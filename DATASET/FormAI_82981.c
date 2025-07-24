//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
  if(num <= 1)
    return 0;
  for(int i = 2; i <= num/2; i++) {
    if(num % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, i = 2;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);
  printf("The first %d prime numbers are: ", n);

  while(n > 0) {
    if(isPrime(i)) {
      printf("%d ", i);
      n--;
    }
    i++;
  }
  return 0;
}
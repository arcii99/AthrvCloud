//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>

int isPrime(int num);

int main() {
  int n, i, count = 0;
  printf("Enter the number of prime numbers you wish to generate: ");
  scanf("%d", &n);
  printf("\nGenerating the first %d prime numbers:\n", n);
  
  for(i=2; count<n; i++) {
    if(isPrime(i)) {
      printf("%d\n", i);
      count++;
    }
  }
  
  return 0;
}

int isPrime(int num) {
  int i;
  for(i=2; i<=num/2; i++) {
    if(num%i == 0) {
      return 0;
    }
  }
  return 1;
}
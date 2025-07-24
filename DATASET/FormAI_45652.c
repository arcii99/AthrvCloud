//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>

int isPrime(int num);

int main() {
  printf("Welcome to the Prime Number Generator!\n");
  printf("This program will generate prime numbers up to the number you choose.\n");

  int maxNum;
  printf("Enter the maximum number: ");
  scanf("%d", &maxNum);

  printf("Calculating...");
  if(maxNum <= 1) {
    printf("\nNo prime numbers found.");
    return 0;
  }

  for(int i=2; i<=maxNum; i++) {
    if(isPrime(i)) {
      printf("\n%d is prime!", i);
    }
  }

  printf("\nDone!\n");
  return 0;
}

int isPrime(int num) {
  if(num == 2 || num == 3) {
    return 1;
  }

  if(num%2 == 0) {
    return 0;
  }

  for(int i=3; i*i<=num; i+=2) {
    if(num%i == 0) {
      return 0;
    }
  }

  return 1;
}
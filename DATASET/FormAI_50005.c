//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Prime Number Generator!\n");
  
  int i, j, isPrime;
  for(i = 2; i <= 100; i++) {
    isPrime = 1;
    for(j = 2; j <= i/2; j++) {
      if(i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if(isPrime == 1) {
      printf("%d is a prime number!\n", i);
    } else {
      printf("%d is not a prime number...\n", i);
    }
  }

  printf("Thank you for using the Prime Number Generator! Remember, every number is special in its own way, even if it's not Prime!\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int main() {
  int num, i = 1, j = 1;
  
  printf("Welcome to the Prime Number Generator!\n");
  printf("Please enter a number to start generating all the prime numbers up to that number: ");
  scanf("%d", &num);
  
  printf("\nGenerating prime numbers up to %d:\n", num);
  
  while (i <= num) {
    bool prime = true;
    
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }
    
    if (prime && i != 1) {
      printf("%d is a prime number!\n", i);
    }
    else {
      printf("%d is not a prime number :(\n", i);
    }
    
    i++;
  }
  
  printf("\nAll prime numbers up to %d have been generated. Hope you had fun!\n", num);
  
  return 0;
}
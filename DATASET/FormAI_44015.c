//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, is_prime, i, flag;

  printf("Welcome to the Prime Number Generator!\n");

  printf("Please enter a positive integer: ");
  scanf("%d", &num);

  printf("Calculating...\n");

  /* check if num is a prime */
  is_prime = 1; /* assume that num is a prime number */
  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      is_prime = 0; /* num is not a prime */
      break;
    }
  }

  if (is_prime == 1) {
    printf("%d is a prime number!\n", num);
  }
  else {
    printf("%d is not a prime number :(\n", num);
    printf("Here are the prime numbers up to %d:\n", num);
    for (i = 2; i <= num; ++i) {
      flag = 1;
      /* check if i is a prime */
      for (int j = 2; j <= i / 2; ++j) {
        if (i % j == 0) {
          flag = 0; /* i is not a prime */
          break;
        }
      }
      if (flag == 1)
        printf("%d\n", i);
    }
  }

  printf("Thank you for using the Prime Number Generator!\n");

  return 0;
}
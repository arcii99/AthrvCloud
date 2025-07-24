//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("SURPRISE!!! I'm a prime number generator!\n");

  int num, count = 0;
  printf("Enter a number: ");
  scanf("%d", &num);

  if (num <= 1) {
    printf("No prime numbers exist below or equal to %d.", num);
    return 0;
  }

  printf("The prime numbers below %d are: \n", num);

  for (int i = 2; i <= num; i++) {
    bool isPrime = true;

    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      printf("%d ", i);
      count++;
    }
  }

  printf("\n\nThere are a total of %d prime numbers below %d.\n", count, num);

  printf("\nThis is a unique prime number generator, isn't it? ;)\n");

  return 0;
}
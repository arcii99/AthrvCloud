//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>

int main() {
  int num, i, count;

  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &num);

  printf("The first %d prime numbers are: \n", num);

  for (i = 2, count = 0; count < num; i++) {
    int prime = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }

    if (prime) {
      printf("%d ", i);
      count++;
    }
  }

  return 0;
}
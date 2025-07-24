//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>

int main() {
  int i, j, flag, n;
  
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &n);
  
  // First prime number is 2
  printf("2 ");

  // Check for prime numbers starting from 3
  for (i = 3; i <= n; i++) {
    flag = 1;

    // Check if i is prime
    for (j = 2; j <= i / 2; j++)
      if (i % j == 0)
        flag = 0;

    // If i is prime, print it
    if (flag)
      printf("%d ", i);
  }
  
  return 0;
}
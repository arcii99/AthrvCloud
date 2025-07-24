//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int main() {
  int i, j, num, flag;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  if (num < 2) {
    printf("There are no primes less than %d\n", num);
  } else {
    printf("Prime numbers less than %d are:\n", num);
    printf("2\n"); // 2 is the first prime number

    for (i = 3; i <= num; i += 2) { // start at 3 and skip even numbers
      flag = 1; // flag initialized to 1 (true)

      for (j = 3; j * j <= i; j += 2) { // start at 3 and skip even numbers
        if (i % j == 0) { // i is divisible by j, not a prime number
          flag = 0; // set flag to 0 (false)
          break; // exit inner loop
        }
      }

      if (flag == 1) { // flag is still 1, i is a prime number
        printf("%d\n", i);
      }
    }
  }

  return 0;
}
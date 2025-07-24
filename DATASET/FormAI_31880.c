//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>

int main() {
  int num, status, i, j;

  printf("Let's generate some prime numbers! Enter a positive integer: ");
  scanf("%d", &num); // take user input

  for (i=2; i<=num; i++) { // loop through all the numbers up to input num
    status = 1; // assume current number is prime
    for (j=2; j<i; j++) { // loop through all the numbers less than i
      if (i%j == 0) { // check if i is divisible by any number less than i
        status = 0; // if yes, then i is not prime
        break;
      }
    }
    if (status == 1) { // if i is prime, then print it to console
      printf("%d ", i);
    }
  }
  printf("\n");

  printf("Woohoo! We generated all prime numbers from 2 to %d.", num);
  return 0;
}
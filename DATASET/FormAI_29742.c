//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Whoa, you're in for a ride! We're going to generate prime numbers!\n");

  int num, i, j, flag;
  printf("Enter the range up to which you want to generate prime numbers: ");
  scanf("%d", &num);

  printf("Here are the prime numbers up to %d: ", num);

  // iterate through every number up to the input number
  for(i=2; i<=num; i++) {
    // assume the current number is prime until proven otherwise
    flag = 1;
    // iterate through every number smaller than the current number
    for(j=2; j<i; j++) {
      // if the current number is divisible by any smaller number, then it's not prime
      if(i % j == 0) {
        flag = 0;
        break;
      }
    }
    // if the current number survived the inner loop, it is prime
    if(flag == 1) {
      printf("%d ", i);
    }
  }

  printf("\nWhew, that was a lot of code! Hope you got some nice prime numbers out of it.");
  return 0;
}
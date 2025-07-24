//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>

int main() {

  // Declare variables
  int num, i, j, flag;

  // Ask user to input a number
  printf("Enter a number: ");
  scanf("%d", &num);

  // Loop through all numbers from 1 to num
  for(i = 1; i <= num; i++) {

    // Assume number is prime until proven otherwise
    flag = 1;

    // Check if i is divisible by any number between 2 and i-1
    for(j = 2; j < i; j++) {
      if(i % j == 0) {
        flag = 0;
        break;
      }
    }

    // If number is prime, print it
    if(flag == 1) {
      printf("%d\n", i);
    }
  }

  return 0;
}
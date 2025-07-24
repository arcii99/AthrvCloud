//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void celebrate() {
  printf("Hurray! No errors!\n");
  printf("ヽ(´▽`)/ ヽ(´▽`)/ ヽ(´▽`)/\n");
}

void apologize() {
  printf("Oops, something went wrong. Try again!\n");
  printf("(ﾉД`)ｼｸｼｸ\n");
}

int main() {
  srand(time(NULL)); // seed random number generator

  // generate random number from 1 to 10
  int num = rand() % 10 + 1;
  
  // handle error if number is not between 1 and 10
  if (num < 1 || num > 10) {
    apologize(); // Sorry, try again!
    return 1; // Exit program with error code 1
  }
  
  // print out the randomly generated number
  printf("Your lucky number is %d!\n", num);
  
  if (num == 7) {
    celebrate(); // Hurray, no errors!
  }
  else {
    apologize(); // Sorry, try again!
  }

  return 0; // Exit program with no errors
}
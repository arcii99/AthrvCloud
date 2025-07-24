//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize random seed
  srand(time(NULL));

  // initialize variables
  int num1, num2, result, input;

  // generate two random numbers between 0 and 10
  num1 = rand() % 11;
  num2 = rand() % 11;

  // calculate the result of the two numbers
  result = num1 + num2;

  // print the puzzle to the user
  printf("What is %d + %d?\n", num1, num2);

  // loop until the user inputs the correct answer
  while(1) {
    // get user input
    scanf("%d", &input);

    // check if the input is correct
    if(input == result) {
      printf("You solved the puzzle! Well done!\n");
      break;
    } else {
      printf("Incorrect, please try again.\n");
    }
  }

  return 0;
}
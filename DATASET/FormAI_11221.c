//FormAI DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, operator, answer, user_answer;

  srand(time(NULL)); // seed random number generator with current time

  // generate two random numbers between 1 and 100
  num1 = (rand() % 100) + 1;
  num2 = (rand() % 100) + 1;

  // generate random arithmetic operator
  operator = rand() % 4;

  switch (operator) {
    case 0: // addition
      answer = num1 + num2;
      printf("What is %d + %d?\n", num1, num2);
      break;
    case 1: // subtraction
      answer = num1 - num2;
      printf("What is %d - %d?\n", num1, num2);
      break;
    case 2: // multiplication
      answer = num1 * num2;
      printf("What is %d * %d?\n", num1, num2);
      break;
    case 3: // division
      answer = num1 / num2;
      printf("What is %d / %d?\n", num1, num2);
      break;
  }

  // get user's answer
  scanf("%d", &user_answer);

  // check if user's answer is correct
  if (user_answer == answer) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The answer was %d.\n", answer);
  }

  return 0;
}
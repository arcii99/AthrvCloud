//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // initialize seed for random number generator
  int num1 = rand() % 100 + 1; // generate random number between 1 and 100
  int num2 = rand() % 100 + 1; // generate another random number between 1 and 100

  // prompt user to solve equation
  printf("Solve the following equation for x: \n");
  printf("%d * x + %d = %d \n", num1, num2, num1 * num2);

  // get user input
  int userAnswer;
  scanf("%d", &userAnswer);

  // calculate correct answer
  int correctAnswer = (num1 * num2) / num1;

  // check if user's answer is correct
  if (userAnswer == correctAnswer) {
    printf("Congratulations! Your answer is correct. \n");
  } 
  else {
    printf("Sorry, your answer is incorrect. The correct answer is %d. \n", correctAnswer);
  }

  return 0;
}
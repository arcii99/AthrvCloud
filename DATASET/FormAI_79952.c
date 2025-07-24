//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate two random numbers
  int num1 = rand() % 100;
  int num2 = rand() % 100;

  // Print a cheerful message to the user
  printf("Welcome to the Math Exercise Program! Today we'll be practicing addition.\n\n");

  // Prompt the user to solve the math problem
  printf("What is %d + %d?\n", num1, num2);

  // Read the user's answer from the command line
  int answer;
  scanf("%d", &answer);

  // Check the user's answer
  if (answer == (num1 + num2)) {
    printf("\nCongratulations! You got the right answer! You're a math superstar!\n");
  } else {
    printf("\nI'm sorry, that's incorrect. The correct answer is %d.\n", (num1 + num2));
  }

  // Thank the user for practicing math with us
  printf("\nThanks for playing! Come back soon to improve your math skills!\n");

  return 0;
}
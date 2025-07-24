//FormAI DATASET v1.0 Category: Math exercise ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // Initialize random seed

  int num1 = rand() % 10; // Generate random number between 0-9
  int num2 = rand() % 10;

  printf("What is the result of %d + %d?\n", num1, num2);
  
  int userAnswer;
  scanf("%d", &userAnswer);

  int correctAnswer = num1 + num2;

  if (userAnswer == correctAnswer) {
    printf("Congratulations! Your answer %d is correct.\n", userAnswer);
  } else {
    printf("Sorry, your answer %d is incorrect. The correct answer is %d.\n", userAnswer, correctAnswer);
  }

  return 0;
}
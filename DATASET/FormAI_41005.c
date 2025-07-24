//FormAI DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Introspection
  printf("I am a math exercise program!\n");

  // Generate random numbers
  int num1 = rand() % 100;
  int num2 = rand() % 100;

  // Present the user with the exercise
  printf("What is the result of %d + %d?\n", num1, num2);

  // Capture the user's input
  int userAnswer;
  scanf("%d", &userAnswer);

  // Calculate the correct answer
  int correctAnswer = num1 + num2;

  // Check the answer
  if (userAnswer == correctAnswer) {
    printf("Congratulations! You got it right!\n");
  } else {
    printf("Sorry, that's not correct. The correct answer is %d\n", correctAnswer);
  }

  return 0;
}
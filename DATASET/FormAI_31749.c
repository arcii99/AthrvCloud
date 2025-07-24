//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // generate two random numbers between 1 and 10
  srand(time(0));
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;

  // display the question to the user
  printf("What is %d + %d?\n", num1, num2);

  // get the user's answer
  int userAnswer;
  scanf("%d", &userAnswer);

  // check if the user's answer is correct
  int correctAnswer = num1 + num2;
  if (userAnswer == correctAnswer) {
    printf("Congratulations! %d is the correct answer!\n", correctAnswer);
  } else {
    printf("Sorry, %d is not the correct answer. The correct answer is %d.\n", userAnswer, correctAnswer);
  }

  return 0;
}
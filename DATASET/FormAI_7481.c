//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Initialize the random function
  srand(time(0));

  // Generate two random numbers between 1 and 10
  int num1 = rand() % 10 + 1;
  int num2 = rand() % 10 + 1;

  // Ask the user the sum of the two numbers
  int answer;
  printf("What is the sum of %d and %d?\n", num1, num2);
  scanf("%d", &answer);

  // Compute the correct answer and compare it to the user's answer
  int expectedAnswer = num1 + num2;
  if (answer == expectedAnswer) {
    printf("Congratulations! You got the answer right.\n");
  } else {
    printf("Sorry, the correct answer is %d\n", expectedAnswer);
  }

  return 0;
}
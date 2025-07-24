//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates a random math exercise.
   The user has to solve the exercise and gets a score for the answer. */

int main() {
  srand(time(NULL));  // seeds the random number generator with the current time

  int a = rand() % 100;  // generates a random number between 0 and 99
  int b = rand() % 100;  // generates another random number between 0 and 99
  int op = rand() % 3;   // generates a random number between 0 and 2 to determine the operation

  int result;            // variable to store the correct result
  int answer;            // variable to store the user's answer
  int score = 0;         // variable to store the user's score

  switch (op) {          // determines the operation based on the random number
    case 0:             // addition
      printf("What is %d + %d? ", a, b);
      result = a + b;   // calculates the correct result
      break;
    case 1:             // subtraction
      printf("What is %d - %d? ", a, b);
      result = a - b;   // calculates the correct result
      break;
    case 2:             // multiplication
      printf("What is %d * %d? ", a, b);
      result = a * b;   // calculates the correct result
      break;
  }

  scanf("%d", &answer);  // reads the user's answer from the console

  if (answer == result) {         // checks if the answer is correct
    printf("Correct!\n");
    score = 10;                   // assigns a score of 10 to a correct answer
  } else {
    printf("Incorrect. The answer is %d.\n", result);
  }

  printf("Your score is %d.\n", score);  // prints the user's score

  return 0;
}
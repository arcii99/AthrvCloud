//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initializes the random number generator with the current time

  int a = rand() % 10 + 1; // Generates a random integer between 1 and 10 (inclusive)
  int b = rand() % 10 + 1; // Generates a second random integer between 1 and 10 (inclusive)
  int result; // Initializes the variable for the user's answer

  printf("Solve for x: %d * x + %d = %d\n", a, b, a * b); // Prompts the user to solve the equation

  scanf("%d", &result); // Reads the user's answer from input

  if (result == (a * b - b)) { // Checks if the user's answer is correct
    printf("Congratulations, your answer is correct!"); // Prints a success message
  }
  else { // If the user's answer is incorrect
    printf("Sorry, your answer is incorrect. The correct answer is %d", a * b - b); // Prints a failure message with the correct answer
  }

  return 0;
}
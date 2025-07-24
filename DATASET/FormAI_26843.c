//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, result, answer, tries;
  srand(time(0)); // Seed random number generator
  tries = 0;
  printf("Let's practice some math!\n");
  printf("========================\n");
  printf("You will be given two random numbers to add together.\n");
  printf("Please enter the correct answer.\n");
  while (tries < 5) { // 5 tries maximum
    num1 = rand() % 100;
    num2 = rand() % 100;
    result = num1 + num2;
    printf("\nWhat is %d + %d? ", num1, num2);
    scanf("%d", &answer);
    if (answer == result) {
      printf("Correct!\n");
      tries++;
    } else {
      printf("Sorry, that's not correct. Try again.\n");
    }
  }
  printf("\nCongratulations! You completed the math exercise.\n");
  printf("You got %d out of 5 correct.\n", tries);
  return 0;
}
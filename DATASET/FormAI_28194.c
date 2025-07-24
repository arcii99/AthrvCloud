//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // set the seed for the random number generator

  int num1 = rand() % 100; // get a random number between 0 and 99
  int num2 = rand() % 100; // get another random number between 0 and 99

  printf("What is the sum of %d and %d?\n", num1, num2);

  int answer;
  scanf("%d", &answer);

  int correct_answer = num1 + num2;

  if (answer == correct_answer) {
    printf("Correct!\n");
  } else {
    printf("Sorry, the correct answer is %d\n", correct_answer);
  }

  return 0;
}
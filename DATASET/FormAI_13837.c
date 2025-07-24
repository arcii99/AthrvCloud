//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables to store user input and random integers
  int user_input, rand_int1, rand_int2, sum, product;
  char operator;

  // Seed the random number generator
  srand(time(NULL));

  // Generate two random integers between 1 and 10 inclusive
  rand_int1 = (rand() % 10) + 1;
  rand_int2 = (rand() % 10) + 1;

  // Randomly select an operator for the math exercise
  int operator_choice = rand() % 2;
  if (operator_choice == 0) {
    operator = '+';
    sum = rand_int1 + rand_int2;
  } else {
    operator = '*';
    product = rand_int1 * rand_int2;
  }

  // Prompt the user with the math exercise
  printf("What is %d %c %d?\n", rand_int1, operator, rand_int2);

  // Receive input from the user
  scanf("%d", &user_input);

  // Determine if the user's answer was correct and give feedback
  if (operator_choice == 0) {
    if (user_input == sum) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The correct answer is %d.\n", sum);
    }
  } else {
    if (user_input == product) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The correct answer is %d.\n", product);
    }
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num1, num2, result;

  // Set random seed
  srand(time(0));

  // Generate random numbers
  num1 = rand() % 10;
  num2 = rand() % 10;

  printf("Let's do some math! What is %d + %d?\n", num1, num2);

  // Read user input
  scanf("%d", &result);

  // Check for error
  if (result != num1 + num2) {
    printf("Error: Your math skills are as bad as mine. Let's try again...\n");
    return 1;
  }

  printf("Congratulations! You got it right! Now, let's divide by 0...\n");

  // Divide by 0
  result = num1 / 0;

  // Check for error
  if (result) {
    printf("Error: Looks like we created a blackhole. Good luck surviving that...\n");
    return 1;
  }

  printf("Oops...I guess we both need to work on our math skills. Have a nice day!\n");

  return 0;
}
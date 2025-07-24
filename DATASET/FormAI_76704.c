//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int n1, n2;
  float solution;

  printf("Welcome to the Math Challenge, let's test your math skills!\n");
  printf("Enter two numbers to multiply:\n");
  scanf("%d %d", &n1, &n2);

  // Generate a random exponent value between 2 and 7
  int exponent = rand() % 6 + 2;

  printf("Now, solve this equation: %d * %d ^ %d\n", n1, n2, exponent);

  // Calculate solution
  solution = n1 * pow(n2, exponent);

  // Retrieve user input
  float user_answer;
  scanf("%f", &user_answer);

  // Compare user answer to the correct solution
  if (user_answer == solution) {
    printf("Congratulations, you solved the challenge!\n");
  } else {
    printf("Sorry, that's incorrect. The correct answer is %0.2f\n", solution);
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  // Initialize variables
  int num1, num2, num3;
  float answer;

  // Set random seed
  srand(time(NULL));

  // Generate random numbers between 1 and 10
  num1 = rand() % 10 + 1;
  num2 = rand() % 10 + 1;
  num3 = rand() % 10 + 1;

  // Solve equation
  answer = sqrt(num1) + pow(num2, 2) * num3;

  // Print problem and answer
  printf("Solve the following equation:\n");
  printf("sqrt(%d) + %d^2 * %d = ", num1, num2, num3);

  // Get user's answer
  float user_answer;
  scanf("%f", &user_answer);

  // Compare user's answer with correct answer
  if (fabs(user_answer - answer) < 0.001) {
    printf("Congratulations! Your answer is correct.\n");
  } else {
    printf("Sorry, your answer is incorrect. The correct answer is %.2f.\n", answer);
  }
  
  return 0;
}
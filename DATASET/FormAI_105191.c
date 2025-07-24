//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
  float weight, height, bmi;
  int steps, goal;

  printf("Welcome to your Personal Fitness Tracker!\n");
  printf("Please enter your current weight in kilograms: ");
  scanf("%f", &weight);
  printf("Please enter your current height in meters: ");
  scanf("%f", &height);

  // Calculate BMI
  bmi = weight / (height * height);
  printf("Your BMI is %.2f.\n", bmi);

  // Set daily step goal
  printf("Please enter your daily step goal: ");
  scanf("%d", &goal);

  // Record daily steps
  printf("How many steps did you take today? ");
  scanf("%d", &steps);
  printf("You took %d steps today.\n", steps);

  if (steps >= goal)
    printf("Congratulations! You've reached your step goal for today!\n");
  else
    printf("Keep going! You're %d steps away from your goal.\n", goal - steps);

  return 0;
}
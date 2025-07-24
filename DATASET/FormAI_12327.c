//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>

int main() {
  int steps, calories;
  float distance, time;

  printf("Welcome to the Fitness Tracker!\n");

  // prompting user for input
  printf("Please enter the number of steps you took today: ");
  scanf("%d", &steps);

  printf("Please enter the amount of time spent walking (in minutes): ");
  scanf("%f", &time);

  printf("Please enter your weight (in pounds): ");
  float weight;
  scanf("%f", &weight);

  // calculating distance traveled and calories burned
  distance = steps * 0.0005; // assuming average step distance is 0.5 meters
  calories = (0.57 * weight * time) / 60;

  // displaying result to user
  printf("\nTotal distance traveled: %.2f kilometers", distance);
  printf("\nTotal calories burned: %d", calories);

  return 0;
}
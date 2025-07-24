//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>

int main() {
  float weight, height;
  int age;
  char gender;
  float caloriesBurned, bmi;
  int steps, minutesActive;

  printf("Welcome to the C Fitness Tracker!\n");
  
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);

  printf("Please enter your height in meters: ");
  scanf("%f", &height);

  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Please enter your gender (M/F): ");
  scanf("%c", &gender);

  printf("Please enter the number of steps you've taken today: ");
  scanf("%d", &steps);

  printf("Please enter the number of minutes you've been active today: ");
  scanf("%d", &minutesActive);

  // Calculate BMI (Body Mass Index)
  bmi = weight / (height * height);

  // Calculate BMR (Basal Metabolic Rate)
  if (gender == 'M') {
    caloriesBurned = 66 + (13.7 * weight) + (5 * (height * 100)) - (6.8 * age);
  } else if (gender == 'F') {
    caloriesBurned = 655 + (9.6 * weight) + (1.8 * (height * 100)) - (4.7 * age);
  }

  // Calculate Calories burned
  caloriesBurned += (steps / 20.0) + (minutesActive * 4.0);

  printf("Your BMI is: %f\n", bmi);
  printf("Your BMR is: %f\n", caloriesBurned);
  printf("You've taken %d steps today.\n", steps);
  printf("You've been active for %d minutes today.\n", minutesActive);

  return 0;
}
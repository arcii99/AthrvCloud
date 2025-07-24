//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>

int main() {
  // Declare variables
  float weight, height, bmi;
  int steps, calories;

  // Prompt user for input
  printf("Please enter your weight (kg): ");
  scanf("%f", &weight);

  printf("Please enter your height (m): ");
  scanf("%f", &height);

  printf("Please enter the number of steps you took today: ");
  scanf("%d", &steps);

  // Calculate BMI
  bmi = weight / (height * height);
  printf("Your BMI is: %.1f\n", bmi);

  // Determine BMI category
  if (bmi < 18.5) {
    printf("Underweight\n");
  } else if (bmi >= 18.5 && bmi < 25) {
    printf("Normal weight\n");
  } else if (bmi >= 25 && bmi < 30) {
    printf("Overweight\n");
  } else {
    printf("Obese\n");
  }

  // Calculate calories burned
  calories = steps * 0.04;
  printf("You burned %d calories today.\n", calories);

  return 0; 
}
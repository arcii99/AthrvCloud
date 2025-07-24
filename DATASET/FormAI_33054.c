//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
  float bmi = weight / (height * height);
  return bmi;
}

int main() {
  float weight, height, bmi;
  int age, steps, waterIntake, caloriesBurned;

  // Get user inputs
  printf("Welcome to C Fitness Tracker!\n");
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);
  printf("Please enter your height in meters: ");
  scanf("%f", &height);
  printf("Please enter your age in years: ");
  scanf("%d", &age);
  printf("Please enter the number of steps you took today: ");
  scanf("%d", &steps);

  // Calculate BMI and display result
  bmi = calculateBMI(weight, height);
  printf("Your BMI is %.2f\n", bmi);

  // Calculate recommended water intake and display result
  waterIntake = age * 35;
  printf("You should drink at least %d mL of water per day\n", waterIntake);

  // Calculate calories burned based on steps taken and display result
  caloriesBurned = steps * 0.05;
  printf("You burned %d calories today\n", caloriesBurned);

  return 0;
}
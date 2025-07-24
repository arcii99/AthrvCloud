//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>

int main() {
  float weight, height, BMI;
  int minutes, caloriesBurned;

  // Get user input for weight and height
  printf("Enter your weight in kilograms: ");
  scanf("%f", &weight);
  printf("Enter your height in meters: ");
  scanf("%f", &height);

  // Calculate BMI
  BMI = weight / (height * height);
  printf("Your BMI is: %.2f\n", BMI);

  // Ask user for exercise details
  printf("How many minutes did you exercise today? ");
  scanf("%d", &minutes);

  // Calculate calories burned based on activity level and weight
  if (BMI < 18.5) {
    // Underweight
    caloriesBurned = minutes * 6 * (int) weight;
  } else if (BMI >= 18.5 && BMI < 25) {
    // Normal weight
    caloriesBurned = minutes * 4 * (int) weight;
  } else if (BMI >= 25 && BMI < 30) {
    // Overweight
    caloriesBurned = minutes * 3 * (int) weight;
  } else {
    // Obese
    caloriesBurned = minutes * 2 * (int) weight;
  }

  printf("You burned %d calories today!\n", caloriesBurned);
  
  return 0;
}
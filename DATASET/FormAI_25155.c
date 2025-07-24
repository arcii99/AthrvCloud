//FormAI DATASET v1.0 Category: Data validation ; Style: lively
#include <stdio.h>

int main() {

  float height, weight, bmi;

  printf("Welcome to the BMI calculator!\n");
  printf("Please enter your height in meters: ");
  scanf("%f", &height);

  // Input validation for height
  while (height <= 0) {
    printf("Height cannot be negative or zero. Please enter a valid height in meters: ");
    scanf("%f", &height);
  }

  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);

  // Input validation for weight
  while (weight <= 0) {
    printf("Weight cannot be negative or zero. Please enter a valid weight in kilograms: ");
    scanf("%f", &weight);
  }

  bmi = weight / (height * height); // Formula to calculate BMI

  // Output BMI and corresponding message
  printf("Your BMI is %.2f\n", bmi);
  if (bmi < 18.5) {
    printf("You are underweight.\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("You have a healthy weight.\n");
  } else if (bmi >= 25 && bmi <= 29.9) {
    printf("You are overweight.\n");
  } else {
    printf("You are obese.\n");
  }

  return 0;
}
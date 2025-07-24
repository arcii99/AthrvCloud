//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Welcome message
  printf("Welcome to the C Fitness Tracker!\n");

  // User input for height and weight
  printf("Please enter your height (in meters): ");
  float height;
  scanf("%f", &height);
  printf("Please enter your weight (in kilograms): ");
  float weight;
  scanf("%f", &weight);

  // Calculation of BMI
  float bmi = weight / (height * height);
  printf("Your BMI is: %.2f\n", bmi);

  // Health status based on BMI
  if (bmi < 18.5) {
    printf("You are underweight.\n");
  } else if (bmi < 25) {
    printf("Congratulations! Your weight is normal.\n");
  } else if (bmi < 30) {
    printf("You are overweight.\n");
  } else {
    printf("You are obese.\n");
  }

  // User input for exercise duration
  printf("Please enter the duration of your exercise routine (in minutes): ");
  int duration;
  scanf("%d", &duration);

  // Calculation of calories burned
  float calories_burned = (duration / 60.0) * 500.0;
  printf("You have burned %.2f calories!\n", calories_burned);

  // End message
  printf("Thank you for using C Fitness Tracker!\n");

  return 0;
}
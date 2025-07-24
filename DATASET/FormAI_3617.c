//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>

int main() {
  int day, month, year, age, height, weight;
  float bmi;
  char gender;

  printf("Welcome to the Fitness Tracker!\n");
  printf("Please enter your birthdate (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &day, &month, &year);

  printf("Please enter your gender (M/F): ");
  scanf("%c", &gender);

  printf("Please enter your weight (in kg): ");
  scanf("%d", &weight);

  printf("Please enter your height (in cm): ");
  scanf("%d", &height);

  age = 2022 - year; // calculate age
  bmi = (float)weight/((float)height/100 * (float)height/100); // calculate BMI

  // display user's information
  printf("\nYour information:\n");
  printf("Age: %d\n", age);
  printf("Gender: %c\n", gender);
  printf("Weight: %dkg\n", weight);
  printf("Height: %dcm\n", height);
  printf("BMI: %.2f\n", bmi);

  // display user's BMI status
  if (bmi < 18.5) {
    printf("You are underweight.\n");
  } else if (bmi >= 18.5 && bmi < 25.0) {
    printf("Your weight is normal.\n");
  } else if (bmi >= 25.0 && bmi < 30.0) {
    printf("You are overweight.\n");
  } else {
    printf("You are obese.\n");
  }

  return 0;
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  float weight, height, bmi;
  int age;

  printf("Welcome to C Fitness Tracker!\n");

  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);

  printf("Please enter your height in meters: ");
  scanf("%f", &height);

  printf("Please enter your age: ");
  scanf("%d", &age);

  bmi = weight / (height * height);

  printf("Your BMI is %.2f\n", bmi);

  if (bmi < 18.5) {
    printf("You are underweight.\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("You have a normal weight.\n");
  } else if (bmi >= 25 && bmi <= 29.9) {
    printf("You are overweight.\n");
  } else {
    printf("You are obese.\n");
  }

  printf("Your target heart rate is %.0f-%.0f beats per minute.\n", (220 - age) * 0.5, (220 - age) * 0.85);

  return 0;
}
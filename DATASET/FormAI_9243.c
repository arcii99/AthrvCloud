//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>

int main() {
  int weight, height;
  float bmi;

  printf("Welcome to the Fitness Tracker\n\n");
  printf("Please enter your weight in kg: ");
  scanf("%d", &weight);

  printf("Please enter your height in cm: ");
  scanf("%d", &height);

  // Calculate BMI
  bmi = weight / ((height/100.0) * (height/100.0));

  printf("\nYour BMI is: %.2f\n", bmi);

  if (bmi < 18.5) {
    printf("You are underweight. Please consider consulting a doctor or nutritionist.\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("Congratulations! Your BMI is within the healthy range.\n");
  } else if (bmi >= 25.0 && bmi <= 29.9) {
    printf("You are overweight. Please consider a healthier diet and exercise routine.\n");
  } else {
    printf("You are obese. Please consider consulting a doctor or nutritionist.\n");
  }

  return 0;
}
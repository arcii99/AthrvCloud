//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>

int main() {
  int age;
  float weight, height;
  printf("Welcome to C Fitness Tracker!\n");
  
  printf("Please enter your age: ");
  scanf("%d", &age);
  
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);
  
  printf("Please enter your height in meters: ");
  scanf("%f", &height);
  
  float bmi = weight / (height * height);
  printf("Your BMI is: %.2f\n", bmi);
  
  if (bmi < 18.5) {
    printf("You are underweight.\n");
  }
  else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("You are healthy.\n");
  }
  else if (bmi > 24.9 && bmi <= 29.9) {
    printf("You are overweight.\n");
  }
  else {
    printf("You are obese.\n");
  }
  
  printf("Thank you for using C Fitness Tracker!\n");
  return 0;
}
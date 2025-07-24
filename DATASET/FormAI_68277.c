//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  float weight, height, bmi;
  int calorie_goal, calories_burned, calories_consumed;

  printf("Welcome to the C Fitness Tracker!\n");
  printf("Please enter your weight in kg: ");
  scanf("%f", &weight);
  printf("Please enter your height in cm: ");
  scanf("%f", &height);

  bmi = weight / ((height / 100) * (height / 100));
  printf("Your BMI is %.1f\n", bmi);

  printf("Please enter your daily calorie goal: ");
  scanf("%d", &calorie_goal);

  printf("Did you consume any calories today? If so, enter the amount: ");
  scanf("%d", &calories_consumed);

  printf("Did you burn any calories today? If so, enter the amount: ");
  scanf("%d", &calories_burned);

  int remaining_calories = calorie_goal - (calories_consumed - calories_burned);
  if (remaining_calories < 0) {
    printf("You have exceeded your daily calorie goal!\n");
  } else {
    printf("You have %d calories remaining to meet your daily goal.\n", remaining_calories);
  }

  printf("Congratulations on taking the first step towards a healthier lifestyle with C Fitness Tracker!\n");

  return 0;
}
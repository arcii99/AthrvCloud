//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>

int main() {
  
  printf("Welcome to the C Fitness Tracker!\n");
  
  int days = 7;
  float weight, height, bmi = 0, totalCalories = 0;
  int calorieIntake[7] = {0, 0, 0, 0, 0, 0, 0};
  
  printf("Enter your weight in kilograms: \n");
  scanf("%f", &weight);
  
  printf("Enter your height in meters: \n");
  scanf("%f", &height);
  
  bmi = weight / (height * height);
  printf("Your BMI is: %.1f\n", bmi);
  
  if (bmi < 18.5) {
    printf("You are underweight, you should eat more!\n");
  } else if (bmi >= 18.5 && bmi <= 24.9) {
    printf("You are normal weight, good job!\n");
  } else if (bmi >= 25 && bmi <= 29.9) {
    printf("You are overweight, time to hit the gym!\n");
  } else {
    printf("You are obese, time to get serious about your health!\n");
  }
  
  for (int i = 0; i < days; i++) {
    printf("Enter your calorie intake for day %d: \n", i+1);
    scanf("%d", &calorieIntake[i]);
    totalCalories += calorieIntake[i];
  }
  
  printf("Your average calorie intake for the past 7 days is %.1f\n", totalCalories / days);
  
  printf("Thanks for using the C Fitness Tracker, remember to stay active and eat healthily!\n");

  return 0;
}
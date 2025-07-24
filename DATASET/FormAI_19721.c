//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>

int main() {

  float weight, height, age, bmi;
  int steps, heartRate;

  // User inputs
  printf("Enter your weight in kg: ");
  scanf("%f", &weight);

  printf("Enter your height in meters: ");
  scanf("%f", &height);

  printf("Enter your age in years: ");
  scanf("%f", &age);

  printf("Enter your daily step count: ");
  scanf("%d", &steps);

  printf("Enter your current heart rate: ");
  scanf("%d", &heartRate);

  // BMI calculation
  bmi = weight / (height * height);

  // Output BMI result
  printf("\nYour BMI is: %.2f\n", bmi);

  // Output daily step count
  printf("You have been taking %d steps daily.\n\n", steps);

  // Output heart rate
  printf("Your current heart rate is %d bpm.\n", heartRate);

  // Age and heart rate calculations
  int maxHeartRate = 220 - age;
  int targetHeartRate = maxHeartRate * 0.75;

  // Output max heart rate
  printf("Your maximum heart rate is: %d bpm.\n", maxHeartRate);

  // Output target heart rate
  printf("Your target heart rate is: %d bpm.\n", targetHeartRate);

  return 0;
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>

// Function to calculate heart rate based on age
int calculateHeartRate(int age) {
  int maxHeartRate = 220 - age;
  int targetHeartRate = maxHeartRate * 0.7;
  return targetHeartRate;
}

int main() {
  int age, height, weight;
  printf("Welcome to the Fitness Tracker!\n");
  printf("Please enter your age: ");
  scanf("%d", &age);

  int targetHeartRate = calculateHeartRate(age);
  printf("\nYour target heart rate is %d.\n", targetHeartRate);

  printf("Please enter your height (in cm): ");
  scanf("%d", &height);
  printf("Please enter your weight (in kg): ");
  scanf("%d", &weight);

  printf("\nBased on your height and weight, your BMI is %.2f.", weight / ((height/100.0) * (height/100.0)));

  return 0;
}
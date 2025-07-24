//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>

int main() {
  float weight, height, bmi;
  int age, target_hr, rest_hr, max_hr;
  
  printf("Welcome to the C Fitness Tracker!\n");
  
  printf("Please enter your weight in kilograms: ");
  scanf("%f", &weight);
  
  printf("Please enter your height in meters: ");
  scanf("%f", &height);
  
  printf("Please enter your age in years: ");
  scanf("%d", &age);
  
  printf("Please enter your resting heart rate in beats per minute: ");
  scanf("%d", &rest_hr);
  
  printf("Please enter your target heart rate in beats per minute: ");
  scanf("%d", &target_hr);
  
  max_hr = 220 - age;
  
  bmi = weight / (height * height);
  
  printf("\n---Fitness Tracker Results---\n");
  
  printf("Body Mass Index: %0.2f\n", bmi);
  
  printf("Maximum Heart Rate: %d\n", max_hr);
  
  printf("Target Heart Rate: %d - %d beats per minute\n", rest_hr + (target_hr - rest_hr) * 0.5, rest_hr + (target_hr - rest_hr) * 0.85);

  return 0;
}
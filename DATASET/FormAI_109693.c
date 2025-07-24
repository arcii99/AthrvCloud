//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>

// Function to calculate the maximum heart rate based on age
int calculateMaxHeartRate(int age) {
  return 220 - age;
}

// Function to display the heart rate zone based on max heart rate and current heart rate
void displayHeartRateZone(float currentHeartRate, int maxHeartRate) {
  float lowEnd = maxHeartRate * 0.5;
  float highEnd = maxHeartRate * 0.85;
  
  if(currentHeartRate < lowEnd) {
    printf("You are in the low intensity heart rate zone.\n");
  } else if(currentHeartRate >= lowEnd && currentHeartRate < highEnd) {
    printf("You are in the moderate intensity heart rate zone.\n");
  } else {
    printf("You are in the high intensity heart rate zone.\n");
  }
}

int main() {
  int age;
  float currentHeartRate;

  printf("Welcome to the C Fitness Tracker!\n\n");

  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Please enter your current heart rate: ");
  scanf("%f", &currentHeartRate);

  int maxHeartRate = calculateMaxHeartRate(age);
  printf("\nYour maximum heart rate is %d.\n", maxHeartRate);

  displayHeartRateZone(currentHeartRate, maxHeartRate);

  return 0;
}
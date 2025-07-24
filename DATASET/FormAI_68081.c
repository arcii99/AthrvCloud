//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>

/* Structure for storing fitness data */
struct FitnessTracker {
  int minutesExercised;
  int caloriesBurned;
  int heartRate;
};

/* Function to display fitness data */
void displayFitnessData(struct FitnessTracker data) {
  printf("Minutes exercised: %d\n", data.minutesExercised);
  printf("Calories burned: %d\n", data.caloriesBurned);
  printf("Heart rate: %d\n", data.heartRate);
}

/* Function to track fitness data */
void trackFitnessData(struct FitnessTracker* data, int minutes, int calories, int heartRate) {
  data->minutesExercised += minutes;
  data->caloriesBurned += calories;
  data->heartRate = (data->heartRate + heartRate) / 2;
}

int main() {
  /* Create a new FitnessTracker */
  struct FitnessTracker myTracker = {0, 0, 0};
  
  /* Track some fitness data */
  trackFitnessData(&myTracker, 30, 300, 120);  // Exercised for 30 minutes, burned 300 calories, and had a heart rate of 120 bpm
  trackFitnessData(&myTracker, 45, 450, 140);  // Exercised for 45 minutes, burned 450 calories, and had a heart rate of 140 bpm
  
  /* Display the fitness data */
  displayFitnessData(myTracker);
  
  return 0;
}
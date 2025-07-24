//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>

int main() {
  int workoutDays = 5;
  int numSets, numReps, weight;
  float totalDistance = 0.0;
  float totalCalories = 0.0;
  
  printf("Welcome to the Fitness Tracker!\n");
  printf("You will be tracking for %d days.\n", workoutDays);
  printf("Let's start with today's workout...\n\n");
  
  for (int i = 1; i <= workoutDays; i++) {
    printf("Day %d:\n", i);

    // Ask user input for workout details
    printf("Enter number of sets: ");
    scanf("%d", &numSets);
    printf("Enter number of reps: ");
    scanf("%d", &numReps);
    printf("Enter weight lifted (in pounds): ");
    scanf("%d", &weight);

    // Calculate and display workout stats
    float distance = (numSets * numReps * weight) / 20.0;
    totalDistance += distance;
    float calories = (numSets * numReps * weight) / 100.0;
    totalCalories += calories;

    printf("You lifted a total of %d lbs today.\n", numSets * numReps * weight);
    printf("You ran %.2f miles today.\n", distance);
    printf("You burned %.2f calories today.\n\n", calories);
  }

  // Display overall workout stats
  printf("Overall workout stats:\n");
  printf("Total distance traveled: %.2f miles\n", totalDistance);
  printf("Total calories burned: %.2f calories\n", totalCalories);
  
  printf("Thank you for using the Fitness Tracker.\n");
  return 0;
}
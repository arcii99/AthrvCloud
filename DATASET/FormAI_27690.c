//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdbool.h>

// This program is a fitness tracker for tracking the user's calories burned, steps taken, and distance traveled.

int main() {
  int caloriesBurned = 0;
  int stepsTaken = 0;
  float distanceTraveled = 0.0f;
  bool userContinues = true;
  
  printf("Welcome to the C Fitness Tracker!\n\n");

  while (userContinues) {
    printf("Please enter the number of calories you burned today: \n");
    scanf("%d", &caloriesBurned);
    
    printf("Please enter the number of steps you took today: \n");
    scanf("%d", &stepsTaken);
    
    printf("Please enter the distance you traveled today (in km): \n");
    scanf("%f", &distanceTraveled);
    
    printf("\n--- Today's Stats ---\n");
    printf("Calories Burned: %d\n", caloriesBurned);
    printf("Steps Taken: %d\n", stepsTaken);
    printf("Distance Traveled: %.2f km\n", distanceTraveled);
    
    printf("\nContinue tracking? (Y/N)");
    char userResponse;
    scanf(" %c", &userResponse);
    
    if (userResponse == 'N' || userResponse == 'n') {
      userContinues = false;
    }
  }

  printf("\nTracker closed.\n");

  return 0;
}
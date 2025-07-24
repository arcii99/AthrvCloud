//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>

int main() {
  int steps, calories, distance, goal;
  
  printf("Welcome to the Fitness Tracker!\n");
  printf("Please enter your daily goal in number of steps: ");
  scanf("%d", &goal);
  
  printf("\nEnter the number of steps you've taken today: ");
  scanf("%d", &steps);
  
  printf("\nEnter the total distance you've covered (in meters): ");
  scanf("%d", &distance);
  
  calories = steps/20;
  
  printf("\n*** Daily Summary ***\n");
  printf("Steps: %d/%d\n", steps, goal);
  printf("Calories Burned: %d\n", calories);
  printf("Distance Covered: %d meters\n", distance);
  if (steps >= goal) {
    printf("Congratulations, you've reached your daily goal!\n");
  } else {
    printf("Keep going, you're almost there!\n");
  }
  
  return 0;
}
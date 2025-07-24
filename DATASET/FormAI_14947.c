//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>

/* Fitness Tracker Example Program */

int main() {
  int days;
  float total_distance = 0.0;
  float total_calories_burned = 0.0;

  printf("Welcome to your Fitness Tracker!\n");
  printf("How many days would you like to track? ");
  scanf("%d", &days);

  for(int i = 1; i <= days; i++) {
    float distance, calories_burned;

    printf("\nDay %d:\n", i);
    printf("Distance (in miles): ");
    scanf("%f", &distance);
    printf("Calories burned: ");
    scanf("%f", &calories_burned);

    total_distance += distance;
    total_calories_burned += calories_burned;
  }

  printf("\nTotal distance traveled: %.2f miles\n", total_distance);
  printf("Total calories burned: %.2f\n", total_calories_burned);

  if(total_distance > 20.0) {
    printf("Great job on reaching over 20 miles in the past %d days!", days);
  } else {
    printf("Keep up the good work and try to reach over 20 miles in the next %d days.", days);
  }

  return 0;
}
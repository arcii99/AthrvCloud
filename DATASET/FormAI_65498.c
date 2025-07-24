//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>

#define MAX_DAYS 7

int main() {
  int steps[MAX_DAYS];
  int totalSteps = 0, maxDaySteps = 0;
  float averageSteps = 0;

  for(int i = 0; i < MAX_DAYS; i++) {
    printf("Enter steps for day %d: ", i+1);
    scanf("%d", &steps[i]);

    totalSteps += steps[i];

    if(steps[i] > maxDaySteps) {
      maxDaySteps = steps[i];
    }
  }

  averageSteps = (float)totalSteps / MAX_DAYS;

  printf("\n----- Fitness Tracker Report -----\n");
  printf("Total steps for this week: %d\n", totalSteps);
  printf("Average steps per day: %.2f\n", averageSteps);
  printf("Most steps in a day: %d\n", maxDaySteps);

  return 0;
}
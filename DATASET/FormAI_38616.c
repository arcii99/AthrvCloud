//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
  int days, totalPushUps = 0, totalSitUps = 0;
  float totalMiles = 0, avgMilesPerDay;

  printf("Enter the number of days you want to track: ");
  scanf("%d", &days);

  int pushUps[days], sitUps[days];
  float miles[days];

  for (int i = 0; i < days; i++) {
    printf("Day %d\n", i+1);

    printf("Enter number of push-ups: ");
    scanf("%d", &pushUps[i]);
    totalPushUps += pushUps[i];

    printf("Enter number of sit-ups: ");
    scanf("%d", &sitUps[i]);
    totalSitUps += sitUps[i];

    printf("Enter number of miles run: ");
    scanf("%f", &miles[i]);
    totalMiles += miles[i];

    printf("\n");
  }

  avgMilesPerDay = totalMiles / (float)days;

  printf("Total Push-Ups: %d\n", totalPushUps);
  printf("Total Sit-Ups: %d\n", totalSitUps);
  printf("Total Miles: %.2f\n", totalMiles);
  printf("Average Miles Per Day: %.2f\n", avgMilesPerDay);

  return 0;
}
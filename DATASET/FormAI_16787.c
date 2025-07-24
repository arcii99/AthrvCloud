//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdbool.h>

int main() {
   int daysInMonth;
   double weight, goalDistance, currentDistance;
   bool reachedGoal = false;

   printf("Welcome to your Fitness Tracker!\n\n");

   printf("Enter the number of days in the month: ");
   scanf("%d", &daysInMonth);

   printf("\nEnter your starting weight for the month: ");
   scanf("%lf", &weight);

   printf("\nEnter your goal distance to run for the month (in miles): ");
   scanf("%lf", &goalDistance);

   for (int i = 1; i <= daysInMonth; i++) {
      printf("\nDay %d:\n", i);

      printf("Enter the distance you ran today (in miles): ");
      scanf("%lf", &currentDistance);

      weight -= 0.2; // assuming a 0.2lb weight loss for every mile run
      if (currentDistance == goalDistance) {
         reachedGoal = true;
      }

      printf("\nYour weight at the end of the day: %.1lflbs", weight);
      printf("\nTotal distance run so far: %.1lf miles\n", currentDistance * i);

      if (reachedGoal) {
         printf("\nYou have reached your goal distance for the month! Congratulations!\n");
         break;
      }
   }

   return 0;
}
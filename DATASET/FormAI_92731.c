//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>

int main() {
   int day, month, year;
   float weight, distance, steps, calories;

   printf("Welcome to the Happy Fit Tracker!\n");
   printf("Enter today's date (dd/mm/yyyy): ");
   scanf("%d/%d/%d", &day, &month, &year);

   printf("\nEnter your current weight (in kgs): ");
   scanf("%f", &weight);

   printf("\nEnter the distance you covered today (in kms): ");
   scanf("%f", &distance);

   printf("\nEnter the number of steps you've taken today: ");
   scanf("%f", &steps);


   calories = (distance * 50) + (steps * 0.05 * weight);

   printf("\nYour Daily log for today %d/%d/%d\n", day, month, year);
   printf("----------\n");
   printf("Weight\t\tDistance\tSteps\t\tCalories\n");
   printf("-------------------------------------------------\n");
   printf("%.2f kgs\t%.2f kms\t%.2f\t\t%.2f cals\n", weight, distance, steps, calories);

   printf("\nCongratuations on taking steps towards a healthier lifestyle!\n");
   
   return 0;
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>

int main() {
   int currentWeight, desiredWeight, daysLeft, caloriesBurned, caloriesEaten, dailyCalories;

   printf("Enter your current weight in pounds: ");
   scanf("%d", &currentWeight);

   printf("Enter your desired weight in pounds: ");
   scanf("%d", &desiredWeight);

   printf("Enter the number of days left until your goal date: ");
   scanf("%d", &daysLeft);

   printf("Enter the number of calories you burn per day: ");
   scanf("%d", &caloriesBurned);

   printf("Enter the number of calories you eat per day: ");
   scanf("%d", &caloriesEaten);

   // Calculate daily caloric deficit or surplus
   dailyCalories = caloriesBurned - caloriesEaten;

   // Calculate total caloric deficit or surplus based on days left until goal date
   int totalCalories = dailyCalories * daysLeft;

   // Calculate required daily caloric deficit to reach desired weight by goal date
   int requiredDailyCalories = totalCalories / daysLeft;

   printf("\nTo reach your desired weight by your goal date,\n");

   if (dailyCalories >= requiredDailyCalories) {
      printf("You need to maintain your current caloric deficit of %d calories per day", dailyCalories);
   } else {
      printf("You need to increase your caloric deficit to %d calories per day", requiredDailyCalories);
   }

   return 0;
}
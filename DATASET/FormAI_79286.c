//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initializing the variables
    int totalDays, remainingDays, currentDay, daysLeft, caloriesBurned, totalCalories;
    double avgCalories;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    //Asking user input
    printf("Enter total number of days to track your fitness: ");
    scanf("%d", &totalDays);
    
    //Calculations and outputs
    remainingDays = totalDays;
    for(int i = 1; i <= totalDays; i++) {
        printf("\n\nDay %d", i);
        printf("\nEnter calories burned for today: ");
        scanf("%d", &caloriesBurned);
        totalCalories += caloriesBurned;
        remainingDays--;
        avgCalories = (double) totalCalories / i;
        currentDay = tm.tm_yday;
        daysLeft = currentDay + remainingDays;
        printf("\nYou burned %d calories today.", caloriesBurned);
        printf("\nYou have %d calories remaining to meet your goal.", daysLeft);
        printf("\nYour average calories burned per day: %.2lf", avgCalories);
    }
    
    return 0;
}
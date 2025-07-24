//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int caloriesBurned = 0;
    int stepsTaken = 0;
    float hoursOfSleep = 0.0;
    int waterIntake = 0;
    
    time_t now = time(NULL); // current time
    
    printf("Welcome to the Fitness Tracker!\n\n");
    printf("What did you do today? Enter values below:\n\n");
    
    printf("Calories burned: ");
    scanf("%d", &caloriesBurned);
    
    printf("Number of steps taken: ");
    scanf("%d", &stepsTaken);
    
    printf("Hours of sleep: ");
    scanf("%f", &hoursOfSleep);
    
    printf("Water intake (in milliliters): ");
    scanf("%d", &waterIntake);
    
    printf("\n\n");
    printf("--------------------------------------------------------\n");
    printf("Fitness Tracker Report: %s", ctime(&now)); // print current date and time in readable format
    printf("--------------------------------------------------------\n\n");
    
    printf("Calories burned: %d\n", caloriesBurned);
    printf("Steps taken: %d\n", stepsTaken);
    printf("Hours of sleep: %.1f hours\n", hoursOfSleep);
    printf("Water intake: %d milliliters\n\n", waterIntake);
    
    printf("Thanks for using the Fitness Tracker!\n");
    
    return 0;
}
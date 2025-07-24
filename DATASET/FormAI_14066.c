//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integer within a range
int generateRandom(int lower, int upper) 
{
    return (rand() % (upper - lower + 1)) + lower;
}
 
int main() 
{
    srand(time(0)); // Seed the random number generator
 
    int totalDays = 30; // Number of days to track fitness 
    int minSteps = 5000; // Minimum number of steps to take each day 
    int maxSteps = 10000; // Maximum number of steps to take each day 
    int minMinutes = 30; // Minimum number of minutes to exercise each day 
    int maxMinutes = 60; // Maximum number of minutes to exercise each day 

    int daysAchievedSteps = 0; // To track number of days steps goal was achieved 
    int daysAchievedExercise = 0; // To track number of days exercise goal was achieved 
    int totalSteps = 0; // To track total number of steps taken 
    int totalExerciseMinutes = 0; // To track total number of exercise minutes 
    float averageStepsPerDay; // To calculate average number of steps taken per day 
    float averageExerciseMinutesPerDay; // To calculate average number of exercise minutes per day 

    // Loop to track fitness for each day 
    for(int i = 1; i <= totalDays; i++) 
    {
        int steps = generateRandom(minSteps, maxSteps); // Generate random number of steps 
        int exerciseMinutes = generateRandom(minMinutes, maxMinutes); // Generate random number of exercise minutes 
        totalSteps += steps; // Add steps to total steps 
        totalExerciseMinutes += exerciseMinutes; // Add exercise minutes to total exercise minutes 
        
        // Check if step goal was achieved 
        if(steps >= minSteps) 
        {
            daysAchievedSteps++; // Increment number of days step goal was achieved 
        }
        
        // Check if exercise goal was achieved
        if(exerciseMinutes >= minMinutes) 
        {
            daysAchievedExercise++; // Increment number of days exercise goal was achieved 
        }
        
        // Print fitness details for the day 
        printf("Day %d: %d steps, %d minutes of exercise\n", i, steps, exerciseMinutes);
    }
    
    averageStepsPerDay = (float) totalSteps / totalDays; // Calculate average number of steps per day 
    averageExerciseMinutesPerDay = (float) totalExerciseMinutes / totalDays; // Calculate average number of exercise minutes per day
    
    // Print fitness report 
    printf("\nFitness Report:\n");
    printf("Total Steps Taken: %d\n", totalSteps);
    printf("Total Exercise Minutes: %d\n", totalExerciseMinutes);
    printf("Days Step Goal Achieved: %d\n", daysAchievedSteps);
    printf("Days Exercise Goal Achieved: %d\n", daysAchievedExercise);
    printf("Average Steps Per Day: %0.2f\n", averageStepsPerDay);
    printf("Average Exercise Minutes Per Day: %0.2f\n", averageExerciseMinutesPerDay);
    
    return 0;
}
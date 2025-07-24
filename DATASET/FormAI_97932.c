//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>

// Function to calculate the average steps taken per day
float calculateAverageSteps(int totalSteps, int days) {
    return (float)totalSteps / days;
}

// Function to calculate the total calories burned based on steps taken
float calculateTotalCaloriesBurned(int totalSteps) {
    return (float)totalSteps * 0.05;
}

// Function to display the fitness data
void displayFitnessData(int totalSteps, int days) {
    float averageSteps = calculateAverageSteps(totalSteps, days);
    float totalCaloriesBurned = calculateTotalCaloriesBurned(totalSteps);
    
    printf("Fitness Tracker Data:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Days: %d\n", days);
    printf("Average Steps per Day: %.2f\n", averageSteps);
    printf("Total Calories Burned: %.2f\n", totalCaloriesBurned);
}

int main(void) {
    int totalSteps = 100000;
    int days = 30;
    
    displayFitnessData(totalSteps, days);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Initialize variables
    int calories = 0;
    int steps = 0;
    float distance = 0.0;
    float pace = 0.0;
    float speed = 0.0;

    // Get user input
    printf("Enter the number of calories burned: ");
    scanf("%d", &calories);

    printf("Enter the number of steps taken: ");
    scanf("%d", &steps);

    // Calculate distance, pace, and speed
    distance = steps * 0.5;
    pace = 1000 / distance; // Minutes per kilometer
    speed = distance * pace; // Kilometers per hour

    // Display results to user
    printf("\nCalories Burned: %d\n", calories);
    printf("Steps Taken: %d\n", steps);
    printf("Distance Traveled: %.2f km\n", distance);
    printf("Pace: %.2f minutes per kilometer\n", pace);
    printf("Speed: %.2f km per hour\n", speed);

    return 0;
}
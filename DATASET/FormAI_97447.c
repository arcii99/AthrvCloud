//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int steps, caloriesBurned;
    float distanceTraveled, timeTaken, averageSpeed;
    bool isTracking = true;
    
    printf("Welcome to the C Fitness Tracker!\n\n");
    printf("Press '0' to stop tracking.\n\n");

    while(isTracking) {
        printf("Enter the number of steps taken: ");
        scanf("%d", &steps);
        if(steps == 0) {
            isTracking = false;
            break;
        }

        printf("Enter the time taken (in minutes): ");
        scanf("%f", &timeTaken);

        distanceTraveled = steps * 0.52;
        caloriesBurned = steps / 20;
        averageSpeed = distanceTraveled / timeTaken;

        printf("\nYou have traveled a distance of %.2f km.\n", distanceTraveled);
        printf("You have burned %d calories.\n", caloriesBurned);
        printf("Your average speed was %.2f km/h.\n\n", averageSpeed);
    }

    printf("\nTracking stopped. Goodbye!");
    return 0;
}
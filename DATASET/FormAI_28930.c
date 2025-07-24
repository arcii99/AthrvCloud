//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int caloriesBurned = 0;
    int stepsTaken = 0;
    int waterIntake = 0;
    int workoutCount = 0;
    int dayCount = 0;
    srand(time(NULL));

    while(1) {
        printf("Day %d\n", dayCount);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");

        // Calculate steps taken
        int steps = rand() % 10000;
        stepsTaken += steps;
        printf("Steps taken: %d\n", steps);

        // Calculate calories burned
        int calories = rand() % 500;
        caloriesBurned += calories;
        printf("Calories burned: %d\n", calories);

        // Calculate water intake
        int water = rand() % 8;
        waterIntake += water;
        printf("Water intake: %d cups\n", water);

        // Calculate workouts done
        int workouts = rand() % 3;
        workoutCount += workouts;
        printf("Workouts done: %d\n", workouts);

        printf("\n");

        // Check if player reached goals
        if(stepsTaken >= 10000 && caloriesBurned >= 500 && waterIntake >= 8 && workoutCount >= 2) {
            printf("Congratulations! You have reached your fitness goals for the day and survived another day in the post-apocalyptic world.\n");
            break;
        }

        // Check if player has survived for a week
        if(dayCount == 7) {
            printf("You have successfully survived for a week in the post-apocalyptic world.\n");
            break;
        }

        // Increment day count
        dayCount++;
    }

    return 0;
}